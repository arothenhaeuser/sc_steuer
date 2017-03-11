from params import inpt, intern, output

def setDefaultParams(**kwargs):
    inpt.af = 0
    inpt.ajahr = 0
    inpt.alter1 = 0
    inpt.entsch = 0
    inpt.f = 0
    inpt.jfreib = 0
    inpt.jhinzu = 0
    inpt.jre4 = 0
    inpt.jre4ent = 0
    inpt.jvbez = 0
    inpt.krv = 0
    inpt.lzzfreib = 0
    inpt.lzzhinzu = 0
    inpt.pkpv = 0
    inpt.pkv = 0
    inpt.pvs = 0
    inpt.r = 0
    inpt.sonstb = 0
    inpt.sonstent = 0
    inpt.sterbe = 0
    inpt.vbez = 0
    inpt.vbezm = 0
    inpt.vbezs = 0
    inpt.vbs = 0
    inpt.vjahr = 0
    inpt.vkapa = 0
    inpt.vmt = 0
    inpt.zkf = 0
    inpt.zmvb = 0
    inpt.kvz = 0
    inpt.lzz = 1
    inpt.re4 = 0
    inpt.stkl = 1
    inpt.pvz = 0
    for k,v in kwargs.items():
        setattr(inpt, k, v)


def cp(module):
    return {k:getattr(module, k) for k in dir(module) if not k.startswith("__")}