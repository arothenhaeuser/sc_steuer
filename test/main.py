import logging
import subprocess as sp
import time
import utils
import os, sys
import garble

logger = logging.getLogger()

CBMC_GC_DIR = os.environ.get("CBMC", None) if len(sys.argv) < 2 else sys.argv[1]
if CBMC_GC_DIR is None:
    sys.exit("Please provide path to CBMC via args or env (CBMC).")

CBMC_RUN_SERVER = os.path.join(CBMC_GC_DIR, "scripts/run-server")
CBMC_RUN_CLIENT = os.path.join(CBMC_GC_DIR, "scripts/run-client")

BASE_DIR = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
CLIENT_DIR = os.path.join(BASE_DIR, "Client")
SERVER_DIR = os.path.join(BASE_DIR, "Server")
SERVER_INPUTS = os.path.join(SERVER_DIR, "inputs.Server.txt")
CLIENT_INPUTS = os.path.join(CLIENT_DIR, "inputs.Client.txt")
SERVER_OUTPUTS = os.path.join(SERVER_DIR, "outputs.out")


def getInputs():
    from params import inpt
    inputs = {}
    for var in dir(inpt):
        if not var.startswith("__"):
            inputs[var] = 0
    # change inputs here #
    inputs["lzz"] = 1
    inputs["kvz"] = 1
    inputs["pvz"] = 1
    inputs["re4"] = 2500000
    inputs["stkl"] = 2
    return inputs


def calcReferenceOutput(inputs):
    from lst2017 import lst2017
    from params import output
    utils.setDefaultParams(**inputs)
    lst2017()
    ref = utils.cp(output)
    return ref


def generateClientInput(inputs):
    with open(CLIENT_INPUTS, "w") as inp:
        for k, string in garble.get_client_inputs():
            inp.write("{} {}\n".format(string, inputs[k]))


def generateServerInput(inputs):
    with open(SERVER_INPUTS, "w") as inp:
        for k, string in garble.get_server_inputs():
            inp.write("{} {}\n".format(string, inputs[k]))


def runService(cmd, cwd):
    logger.debug("Run: {} in {}".format(cmd, cwd))
    return sp.Popen(cmd, cwd=cwd)


def runServer():
    return runService([CBMC_RUN_SERVER], cwd=SERVER_DIR)


def runClient():
    return runService([CBMC_RUN_CLIENT], cwd=CLIENT_DIR)


def wait(*args):
    while True:
        returns = [proc.poll() for proc in args]
        if all([ret is not None for ret in returns]):
            return returns
        time.sleep(1)


def parseOutput():
    output = {}
    with open(SERVER_OUTPUTS, "r", encoding="UTF-8") as out:
        for line in out:
            key, value = line.split(" ")
            output[key[7:].lower()] = int(value)
    return output


def compare(reference, output):
    diff = {}
    for key, value in reference.items():
        out_val = output.get(key, None)
        if not out_val == value:
            diff[key] = (value, out_val)
    return diff


def main():
    logging.basicConfig(level=logging.DEBUG)
    logging.debug("Using CBMC: {}".format(CBMC_GC_DIR))
    logger.info("Start Test")
    inputs = getInputs()
    logger.debug("Inputs: {}".format({k:v for k,v in inputs.items() if v != 0}))
    generateClientInput(inputs)
    generateServerInput(inputs)
    spid = runServer()
    cpid = runClient()
    wait(spid, cpid)
    output = parseOutput()
    reference = calcReferenceOutput(inputs)
    logger.debug("Shorted Reference: {}".format({k: v for k, v in reference.items() if v != 0}))
    logger.debug("Shorted Output: {}".format({k: v for k, v in output.items() if v != 0}))
    diff = compare(reference, output)
    logger.debug("Difference (target, actual): {}".format(diff))
    logger.info("End Test, Bye")


if __name__ == "__main__":
    main()
