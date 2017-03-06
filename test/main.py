import params.intern as p
from params import inpt, output

TAB123 = (
    (2005, 1, 0.400, 3000, 900),
    (2006, 2, 0.384, 2880, 864),
    (2007, 3, 0.368, 2760, 828),
    (2008, 4, 0.352, 2640, 792),
    (2009, 5, 0.336, 2520, 756),
    (2010, 6, 0.320, 2400, 720),
    (2011, 7, 0.304, 2280, 684),
    (2012, 8, 0.288, 2160, 648),
    (2013, 9, 0.272, 2040, 612),
    (2014, 10, 0.256, 1920, 576),
    (2015, 11, 0.240, 1800, 540),
    (2016, 12, 0.224, 1680, 504),
    (2017, 13, 0.208, 1560, 468),
    (2018, 14, 0.192, 1440, 432),
    (2019, 15, 0.176, 1320, 396),
    (2020, 16, 0.160, 1200, 360),
    (2021, 17, 0.152, 1140, 342),
    (2022, 18, 0.144, 1080, 324),
    (2023, 19, 0.136, 1020, 306),
    (2024, 20, 0.128, 960, 288),
    (2025, 21, 0.120, 900, 270),
    (2026, 22, 0.112, 840, 252),
    (2027, 23, 0.104, 780, 234),
    (2028, 24, 0.096, 720, 216),
    (2029, 25, 0.088, 660, 198),
    (2030, 26, 0.080, 600, 180),
    (2031, 27, 0.072, 540, 162),
    (2032, 28, 0.064, 480, 144),
    (2033, 29, 0.056, 420, 126),
    (2034, 30, 0.048, 360, 108),
    (2035, 31, 0.040, 300, 90),
    (2036, 32, 0.032, 240, 72),
    (2037, 33, 0.024, 180, 54),
    (2038, 34, 0.016, 120, 36),
    (2039, 35, 0.008, 60, 18),
    (2040, 36, 0.000, 0, 0)
)

TAB45 = (
    (2005, 1, 0.400, 1900),
    (2006, 2, 0.384, 1824),
    (2007, 3, 0.368, 1748),
    (2008, 4, 0.352, 1672),
    (2009, 5, 0.336, 1596),
    (2010, 6, 0.320, 1520),
    (2011, 7, 0.304, 1444),
    (2012, 8, 0.288, 1368),
    (2013, 9, 0.272, 1292),
    (2014, 10, 0.256, 1216),
    (2015, 11, 0.240, 1140),
    (2016, 12, 0.224, 1064),
    (2017, 13, 0.208, 988),
    (2018, 14, 0.192, 912),
    (2019, 15, 0.176, 836),
    (2020, 16, 0.160, 760),
    (2021, 17, 0.152, 722),
    (2022, 18, 0.144, 684),
    (2023, 19, 0.136, 646),
    (2024, 20, 0.128, 608),
    (2025, 21, 0.120, 570),
    (2026, 22, 0.112, 532),
    (2027, 23, 0.104, 494),
    (2028, 24, 0.096, 456),
    (2029, 25, 0.088, 418),
    (2030, 26, 0.080, 380),
    (2031, 27, 0.072, 342),
    (2032, 28, 0.064, 304),
    (2033, 29, 0.056, 266),
    (2034, 30, 0.048, 228),
    (2035, 31, 0.040, 190),
    (2036, 32, 0.032, 152),
    (2037, 33, 0.024, 114),
    (2038, 34, 0.016, 76),
    (2039, 35, 0.008, 38),
    (2040, 36, 0.000, 0)
)


def tab123(j, i):
    """
    Maßgebender Prozentsatz,
    Höchstbetrag des Versorgungs-
    freibetrags und Zuschlag zum
    Versorgungsfreibetrag
    gem. § 19 Absatz 2 EStG
    """
    if 1 <= j >= 36:
        return TAB123[j-1][i+1]
    else:
        raise IndexError("{} not in table".format(j))


def tab45(k, i):
    """
    Maßgebender Prozentsatz und
    Höchstbetrag des Altersentlastungs-
    betrags gem. § 24a EStG
    """
    if 1 <= k >= 36:
        return TAB45[k-1][i-2]
    else:
        raise IndexError("{} not in table".format(k))


def tab1(j):
    return tab123(j, 1)


def tab2(j):
    return tab123(j, 2)


def tab3(j):
    return tab123(j, 3)


def tab4(k):
    return tab45(k, 4)


def tab5(k):
    return tab45(k, 5)


def mpara():
    """
    Zuweisung von Werten für bestimmte Sozialversicherungsparameter
    """
    if inpt.krv < 2:
        if inpt.krv == 0:
            p.bbgrv = 76200
        else:
            p.bbgrv = 68400
        p.rvsatzan = 0.0935
        p.tbsvorv = 0.68
    p.bbgkvpv = 52200
    p.kvsatzan = inpt.kvz / 100 + 0.07
    p.kvsatzag = 0.07
    if inpt.pvs == 1:
        p.pvsatzan = 0.01775
        p.pvsatzag = 0.00775
    else:
        p.pvsatzan = 0.01275
        p.pvsatzag = 0.01275
    if inpt.pvz == 1:
        p.pvsatzan = p.pvsatzan + 0.0025
    p.w1stkl5 = 10240
    p.w2stkl5 = 27029
    p.w3stkl5 = 205043
    p.gfb = 8820
    p.solzfrei = 972


def mre4jl():
    """
    Ermittlung des Jahresarbeitslohns
    und der Freibeträge
    § 39b Absatz 2 Satz 2 EStG
    """
    if inpt.lzz == 1:
        p.zre4j = inpt.re4 / 100
        p.zvbezj = inpt.vbez / 100
        p.jlfreib = inpt.lzzfreib / 100
        p.jlhinzu = inpt.lzzhinzu / 100
    elif inpt.lzz == 2:
        p.zre4j = inpt.re4 * 12 / 100
        p.zvbezj = inpt.vbez * 12 / 100
        p.jlfreib = inpt.lzzfreib * 12 / 100
        p.jlhinzu = inpt.lzzhinzu * 12 / 100
    elif inpt.lzz == 3:
        p.zre4j = inpt.re4 * 360 / 7 / 100
        p.zvbezj = inpt.vbez * 360 / 7 / 100
        p.jlfreib = inpt.lzzfreib * 360 / 7 / 100
        p.jlhinzu = inpt.lzzhinzu * 360 / 7 / 100
    else:
        p.zre4j = inpt.re4 * 360 / 100
        p.zvbezj = inpt.vbez * 360 / 100
        p.jlfreib = inpt.lzzfreib * 360 / 100
        p.jlhinzu = inpt.lzzhinzu * 360 / 100
    if inpt.af == 0:
        inpt.f = 1


def mre4():
    """
    Freibeträge für Versorgungsbezüge, Altersentlastungsbetrag
    (§ 39b Absatz 2 Satz 3 EStG)
    """
    if p.zvbezj == 0:
        p.fvbz = 0
        p.fvb = 0
        p.fvbzso = 0
        p.fvbso = 0
    else:
        if inpt.vjahr < 2006:
            p.j = 1
        else:
            if inpt.vjahr < 2040:
                p.j = inpt.vjahr - 2004
            else:
                p.j = 36
        if inpt.lzz == 1:
            p.vbezb = inpt.vbezm * inpt.zmvb + inpt.vbezs
            p.hfvb = tab2(p.j) / 12 * inpt.zmvb
            p.fvbz = tab3(p.j) / 12 * inpt.zmvb
        else:
            p.vbezb = inpt.vbezm * 12 + inpt.vbezs
            p.hfvb = tab2(p.j)
            p.fvbz = tab3(p.j)
        p.fvb = p.vbezb * tab1(p.j) / 100
        if p.fvb > p.hfvb:
            p.fvb = p.hfvb
        if p.fvb > p.zvbezj:
            p.fvb = p.zvbezj
        p.fvbso = p.fvb + p.vbezbso * tab2(p.j) / 100
        if p.fvbso > tab2(p.j):
            p.fvbso = tab2(p.j)
        p.hfvbzso = (p.vbezb + p.vbezbso) / 100 - p.fvbso
        p.fvbzso = p.fvbz + p.vbezbso / 100
        if p.fvbzso > p.hfvbzso:
            p.fvbzso = p.hfvbzso
        if p.fvbzso > tab3(p.j):
            p.fvbzso = tab3(p.j)
        p.hfvbz = p.vbezb / 100 - p.fvb
        if p.fvbz > p.hfvbz:
            p.fvbz = p.hfvbz
    mre4alte()


def mre4alte():
    """
    Altersentlastungsbetrag
    (§ 39b Absatz 2 Satz 3 EStG)
    """
    if inpt.alter1 == 0:
        p.alte = 0
    else:
        if inpt.ajahr < 2006:
            p.k = 1
        else:
            if inpt.ajahr < 2040:
                p.k = inpt.ajahr - 2004
            else:
                p.k = 36
        p.bmg = p.zre4j - p.zvbezj
        p.alte = p.bmg - tab4(p.k)
        p.hbalte = tab5(p.k)
        if p.alte > p.hbalte:
            p.alte = p.hbalte


def mre4abz():
    p.zre4 = p.zre4j - p.fvb - p.alte - p.jlfreib + p.jlhinzu
    if p.zre4 < 0:
        p.zre4 = 0
    p.zre4vp = p.zre4j
    if p.kennvmt == 2:
        p.zre4vp = p.zre4vp - inpt.entsch / 100
    p.zvbez = p.zvbezj - p.fvb
    if p.zvbez < 0:
        p.zvbez = 0


def mberech():
    mztabfb()
    p.vfrb = (p.anp + p.fvb + p.fvbz) * 100
    mlstjahr()
    p.wvfrb = (p.zve - p.gfb) * 100
    if p.wvfrb < 0:
        p.wvfrb = 0
    p.lstjahr = p.st * inpt.f
    uplstlzz()
    upvkvlzz()
    if inpt.zkf > 0:
        p.ztabfb = p.ztabfb + p.kfb
        mre4abz()
        mlstjahr()
        p.jbmg = p.st * inpt.f
    else:
        p.jbmg = p.lstjahr
    msolz()


def mztabfb():
    p.anp = 0
    if p.zvbez >= 0:
        if p.zvbez < p.fvbz:
            p.fvbz = p.zvbez
    if inpt.stkl < 6:
        if p.zvbez > 0:
            if p.zvbez - p.fvbz < 102:
                p.anp = p.zvbez - p.fvbz
            else:
                p.anp = 102
    else:
        p.fvbz = 0
        p.fvbzso = 0
    if inpt.stkl < 6:
        if p.zre4 > p.zvbez:
            if p.zre4 - p.zvbez < 1000:
                p.anp = p.anp + p.zre4 - p.zvbez
            else:
                p.anp = p.anp + 1000
    p.kztab = 1
    if inpt.stkl == 1:
        p.sap = 36
        p.kfb = inpt.zkf * 7356
    elif inpt.stkl == 2:
        p.efa = 1908
        p.sap = 36
        p.kfb = inpt.zkf * 7356
    elif inpt.stkl == 3:
        p.kztab = 2
        p.sap = 36
        p.kfb = inpt.zkf * 7356
    elif inpt.stkl == 4:
        p.sap = 36
        p.kfb = inpt.zkf * 3678
    elif inpt.stkl == 5:
        p.sap = 36
        p.kfb = 0
    else:
        p.kfb = 0
    p.ztabfb = p.efa + p.anp + p.sap + p.fvbz


def mlstjahr():
    upevp()
    if p.kennvmt != 1:
        p.zve = p.zre4 - p.ztabfb - p.vsp
        upmlst()
    else:
        p.zve = p.zre4 - p.ztabfb - p.vsp - inpt.vmt / 100 - inpt.vkapa / 100
        if p.zve < 0:
            p.zve = (p.zve + inpt.vmt / 100 + inpt.vkapa / 100) / 5
            upmlst()
            p.st = p.st * 5
        else:
            upmlst()
            p.stovmt = p.st
            p.zve = p.zve + (inpt.vmt + inpt.vkapa) / 500
            upmlst()
            p.st = (p.st - p.stovmt) * 5 + p.stovmt


def upvkvlzz():
    upvkv()
    p.jw = p.vkv
    upanteil()
    output.vkvlzz = p.anteil1


def upvkv():
    if inpt.pkv > 0:
        if p.vsp2 > p.vsp3:
            p.vkv = p.vsp2 * 100
        else:
            p.vkv = p.vsp3 * 100
    else:
        p.vkv = 0


def uplstlzz():
    p.jw = p.lstjahr * 100
    upanteil()
    output.lstlzz = p.anteil1


def upmlst():
    if p.zve < 1:
        p.zve = 0
        p.x = 0
    else:
        p.x = p.zve / p.kztab
    if inpt.stkl < 5:
        uptab17()
    else:
        mst5_6()


def upevp():
    if inpt.krv > 1:
        p.vsp1 = 0
    else:
        if p.zre4vp > p.bbgrv:
            p.zre4vp = p.bbgrv
        p.vsp1 = p.tbsvorv * p.zre4vp
        p.vsp1 = p.vsp1 * p.rvsatzan
    p.vsp2 = 0.12 * p.zre4vp
    if inpt.stkl == 3:
        p.vhb = 3000
    else:
        p.vhb = 1900
    if p.vsp2 > p.vhb:
        p.vsp2 = p.vhb
    p.vspn = p.vsp1 + p.vsp2
    mvsp()
    if p.vspn > p.vsp:
        p.vsp = p.vspn


def mvsp():
    if p.zre4vp > p.bbgkvpv:
        p.zre4vp = p.bbgkvpv
    if inpt.pkv > 0:
        if inpt.stkl == 6:
            p.vsp3 = 0
        else:
            p.vsp3 = inpt.pkpv * 12 / 100
            if inpt.pkv == 2:
                p.vsp3 = p.vsp3 - p.zre4vp * (p.kvsatzag + p.pvsatzag)
    else:
        p.vsp3 = p.zre4vp * (p.kvsatzan + p.pvsatzan)
    p.vsp = p.vsp3 + p.vsp1


def mst5_6():
    p.zzx = p.x
    if p.zzx > p.w2stkl5:
        p.zx = p.w2stkl5
        p.st = up5_6()
        if p.zzx > p.w3stkl5:
            p.st = p.st + (p.w3stkl5 - p.w2stkl5) * 0.42
            p.st = p.st + (p.zzx - p.w3stkl5) * 0.45
        else:
            p.st = p.st + (p.zzx - p.w2stkl5) * 0.42
    else:
        p.zx = p.zzx
        up5_6()
        if p.zzx > p.w1stkl5:
            p.vergl = p.st
            p.zx = p.w1stkl5
            up5_6()
            p.hoch = p.st + (p.zzx - p.w1stkl5) * 0.42
            if p.hoch < p.vergl:
                p.st = p.hoch
            else:
                p.st = p.vergl


def up5_6():
    p.x = p.zx * 1.25
    uptab17()
    p.st1 = p.st
    p.x = p.zx * 0.75
    uptab17()
    p.st2 = p.st
    p.diff = (p.st1 - p.st2) * 2
    p.mist = p.zx * 0.14
    if p.mist > p.diff:
        p.st = p.mist
    else:
        p.st = p.diff


def msolz():
    p.solzfrei = p.solzfrei * p.kztab
    if p.jbmg > p.solzfrei:
        p.solzj = p.jbmg * 5.5 / 100
        p.solzmin = (p.jbmg - p.solzfrei) * 20 / 100
        if p.solzmin < p.solzj:
            p.solzj = p.solzmin
        p.jw = p.solzj * 100
        upanteil()
        output.solzlzz = p.anteil1
    else:
        output.solzlzz = 0
    if inpt.r > 0:
        p.jw = p.jbmg * 100
        upanteil()
        output.bk = p.anteil1
    else:
        output.bk = 0


def upanteil():
    if inpt.lzz == 1:
        p.anteil1 = p.jw
    elif inpt.lzz == 2:
        p.anteil1 = p.jw / 12
    elif inpt.lzz == 3:
        p.anteil1 = p.jw * 7 / 360
    else:
        p.anteil1 = p.jw / 360


def msonst():
    inpt.lzz = 1
    if inpt.zmvb == 0:
        inpt.zmvb = 12
    if inpt.sonstb == 0:
        output.vkvsonst = 0
        p.lstso = 0
        output.sts = 0
        output.solzs = 0
        output.bks = 0
    else:
        mosonst()
        upvkv()
        output.vkvsonst = p.vkv
        p.zre4j = (inpt.jre4 + inpt.sonstb) / 100
        p.zvbezj = (inpt.jvbez + inpt.vbs) / 100
        p.vbezbso = inpt.sterbe
        mre4sonst()
        mlstjahr()
        p.wvfrbm = (p.zve - p.gfb) * 100
        if p.wvfrbm < 0:
            p.wvfrbm = 0
        upvkv()
        p.wkvsonst = p.vkv - output.vkvsonst
        output.sts = (p.lstso - p.lstoso) * inpt.f
        if output.sts < 0:
            output.sts = 0
        output.solzs = output.sts * 5.5 / 100
        if inpt.r > 0:
            output.bks = output.sts
        else:
            output.bks = 0


def mvmt():
    if inpt.vkapa < 0:
        inpt.vkapa = 0
    if inpt.vmt + inpt.vkapa > 0:
        if p.lstso == 0:
            msonst()
            p.lst1 = p.lstoso
        else:
            p.lst1 = p.lstso
        p.vbezbso = inpt.sterbe + inpt.vkapa
        p.zre4j = (inpt.jre4 + inpt.sonstb + inpt.vmt + inpt.vkapa) / 100
        p.zvbezj = (inpt.jvbez + inpt.vbs + inpt.vkapa) / 100
        p.kennvmt = 2
        mre4sonst()
        mlstjahr()
        p.lst3 = p.st * 100
        mre4abz()
        p.zre4vp = p.zre4vp - inpt.jre4ent / 100 - inpt.sonstent / 100
        p.kennvmt = 1
        mlstjahr()
        p.lst2 = p.st * 100
        output.stv = p.lst2 - p.lst1
        p.lst3 = p.lst3 - p.lst1
        if p.lst3 < output.stv:
            output.stv = p.lst3
        if output.stv < 0:
            output.stv = 0
        else:
            output.stv = output.stv * inpt.f
        output.solzv = output.stv * 5.5 / 100
        if inpt.r > 0:
            output.bkv = output.stv
        else:
            output.bkv = 0
    else:
        output.stv = 0
        output.solzv = 0
        output.bkv = 0


def mosonst():
    p.zre4j = inpt.jre4 / 100
    p.zvbezj = inpt.jvbez / 100
    p.jlfreib = inpt.jfreib / 100
    p.jlhinzu = inpt.jhinzu / 100
    mre4()
    mre4abz()
    p.zre4vp = p.zre4vp - inpt.jre4ent / 100
    mztabfb()
    p.vfrbs1 = (p.anp + p.fvb + p.fvbz) * 100
    p.zve = mlstjahr()
    p.wvfrbo = (p.zve - p.gfb) * 100
    if p.wvfrbo < 0:
        p.wvfrbo = 0
    p.lstoso = p.st * 100


def mre4sonst():
    mre4()
    p.fvb = p.fvbso
    mre4abz()
    p.zre4vp = p.zre4vp - inpt.jre4ent / 100 - inpt.sonstent / 100
    p.fvbz = p.fvbzso
    mztabfb()
    p.vfrbs2 = (p.anp + p.fvb + p.fvbz) * 100 - p.vfrbs1



def uptab17():
    if p.x < p.gfb + 1:
        p.st = 0
    elif p.x < 13770:
        p.y = (p.x - p.gfb) / 10000
        p.rw = p.y * 1007.27
        p.rw = p.rw + 1400
        p.st = p.rw * p.y
    elif p.x < 54058:
        p.y = (p.x - 13769) / 10000
        p.rw = p.y * 223.76
        p.rw = p.rw + 2397
        p.rw = p.rw * p.y
        p.st = p.rw + 939.57
    elif p.x < 256304:
        p.st = p.x * 0.42 - 8475.44
    else:
        p.st = p.x * 0.45 - 16164.53
    p.st = p.st * p.kztab


def lst2017():
    # TODO: Rundungen einfügen
    mpara()
    mre4jl()
    p.vbezbso = 0
    p.kennvmt = 0
    mre4()
    mre4abz()
    mberech()
    msonst()
    mvmt()



if __name__ == "__main__":
    lst2017()