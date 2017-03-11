mapping = {
    'af': 'A',
    'ajahr': 'A',
    'alter1': 'A',
    'entsch': 'A',
    'f': 'A',
    'jfreib': 'A',
    'jhinzu': 'A',
    'jre4': 'B',
    'jre4ent': 'B',
    'jvbez': 'B',
    'krv': 'A',
    'kvz': 'A',
    'lzz': 'B',
    'lzzfreib': 'A',
    'lzzhinzu': 'A',
    'pkpv': 'A',
    'pkv': 'A',
    'pvs': 'A',
    'pvz': 'A',
    'r': 'A',
    're4': 'B',
    'sonstb': 'B',
    'sonstent': 'B',
    'sterbe': 'B',
    'stkl': 'A',
    'vbez': 'B',
    'vbezm': 'B',
    'vbezs': 'B',
    'vbs': 'B',
    'vjahr': 'B',
    'vkapa': 'B',
    'vmt': 'B',
    'zkf': 'A',
    'zmvb': 'B'
}


def get_client_inputs():
    for k, v in mapping.items():
        if v == "B":
            yield k, "INPUT_B_{}".format(k.upper())


def get_server_inputs():
    for k, v in mapping.items():
        if v == "A":
            yield k, "INPUT_A_{}".format(k.upper())