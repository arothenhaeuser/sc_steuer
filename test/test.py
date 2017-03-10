import unittest

import main as m
from params import inpt, intern, output


def resetParams():
    for var in dir(intern):
        if not var.startswith("__"):
            setattr(intern, var, None)
    intern.efa = 0  # Bugfix for Error in PAB ToDo: Discuss the fix
    intern.sap = 0  # Bugfix for Error in PAB ToDo: Discuss the fix
    for var in dir(output):
        if not var.startswith("__"):
            setattr(output, var, None)
    for var in dir(inpt):
        if not var.startswith("__"):
            setattr(inpt, var, None)


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


def setTestTable1():
    setDefaultParams(krv=0, pkv=0, kvz=1.1, pvz=1)


def setRe4Stkl(re4, stkl):
    inpt.re4 = re4
    inpt.stkl = stkl
    inpt.pvz = 0 if inpt.stkl == 2 else 1


class TestMpara(unittest.TestCase):

    def setUp(self):
        resetParams()
        setDefaultParams()

    def test_tt1(self):
        setTestTable1()
        m.mpara()
        self.assertEqual(intern.rvsatzan, 0.0935)
        self.assertEqual(intern.tbsvorv, 0.68)
        self.assertEqual(intern.bbgrv, 76200)
        self.assertEqual(intern.bbgkvpv, 52200)
        self.assertEqual(intern.kvsatzan, 1.1/100 + 0.07)
        self.assertEqual(intern.kvsatzag, 0.07)
        self.assertEqual(intern.pvsatzan, 0.01525)
        self.assertEqual(intern.pvsatzag, 0.01275)
        self.assertEqual(intern.w1stkl5, 10240)
        self.assertEqual(intern.w2stkl5, 27029)
        self.assertEqual(intern.w3stkl5, 205043)
        self.assertEqual(intern.gfb, 8820)
        self.assertEqual(intern.solzfrei, 972)

    def test_krv3(self):
        inpt.krv = 2
        m.mpara()
        self.assertEqual(intern.rvsatzan, None)
        self.assertEqual(intern.tbsvorv, None)
        self.assertEqual(intern.bbgrv, None)

    def test_krv1(self):
        inpt.krv = 1
        m.mpara()
        self.assertEqual(intern.rvsatzan, 0.0935)
        self.assertEqual(intern.tbsvorv, 0.68)
        self.assertEqual(intern.bbgrv, 68400)

    def test_krv0(self):
        inpt.krv = 0
        m.mpara()
        self.assertEqual(intern.rvsatzan, 0.0935)
        self.assertEqual(intern.tbsvorv, 0.68)
        self.assertEqual(intern.bbgrv, 76200)

    def test_pvs0(self):
        inpt.pvs = 0
        m.mpara()
        self.assertEqual(intern.pvsatzan, 0.01275)
        self.assertEqual(intern.pvsatzag, 0.01275)

    def test_pvs1(self):
        inpt.pvs = 1
        m.mpara()
        self.assertEqual(intern.pvsatzan, 0.01775)
        self.assertEqual(intern.pvsatzag, 0.00775)

    def test_pvz1(self):
        inpt.pvz = 1
        inpt.pvs = 0
        m.mpara()
        self.assertEqual(intern.pvsatzan, 0.01275 + 0.0025)

    def test_pvz0(self):
        inpt.pvz = 0
        inpt.pvs = 0
        m.mpara()
        self.assertEqual(intern.pvsatzan, 0.01275)


class TestMre4jl(unittest.TestCase):

    def setUp(self):
        resetParams()
        setDefaultParams()

    def test_tt1(self):
        setTestTable1()
        inpt.re4 = 25000
        m.mre4jl()
        self.assertEquals(intern.zre4j, 25000 / 100)
        self.assertEquals(intern.zvbezj, 0)
        self.assertEquals(intern.jlfreib, 0)
        self.assertEquals(intern.jlhinzu, 0)
        self.assertEquals(inpt.f, 1)

    def test_af1(self):
        inpt.af = 1
        m.mre4jl()
        self.assertEqual(inpt.f, 0)

    def test_af0(self):
        inpt.af = 0
        m.mre4jl()
        self.assertEqual(inpt.f, 1)

    def test_lzz(self):
        calc_table = [0, 1/100, 12/100, 360/7/100, 360/100]
        for lzz in range(1, 5):
            resetParams()
            inpt.re4 = 25000
            inpt.vbez = 10
            inpt.lzzfreib = 100
            inpt.lzzhinzu = 1000
            inpt.lzz = lzz
            m.mre4jl()
            self.assertAlmostEquals(intern.zre4j, 25000*calc_table[lzz], lzz)
            self.assertAlmostEquals(intern.zvbezj, 10 * calc_table[lzz], lzz)
            self.assertAlmostEquals(intern.jlfreib, 100 * calc_table[lzz], lzz)
            self.assertAlmostEquals(intern.jlhinzu, 1000 * calc_table[lzz], lzz)


class TestMre4alte(unittest.TestCase):
    def setUp(self):
        resetParams()
        setDefaultParams()

    def test_tt1(self):
        setTestTable1()
        m.mre4alte()
        self.assertEqual(intern.alte, 0)


class TestMre4(unittest.TestCase):
    def setUp(self):
        resetParams()
        setDefaultParams()

    def test_tt1(self):
        setTestTable1()
        intern.zvbezj = 0
        m.mre4()
        self.assertEqual(intern.fvbz, 0)
        self.assertEqual(intern.fvb, 0)
        self.assertEqual(intern.fvbzso, 0)
        self.assertEqual(intern.fvbso, 0)


class TestTesttable1(unittest.TestCase):

    def setUp(self):
        resetParams()
        setDefaultParams(krv=0, pkv=0, kvz=1.1)

    def test_stkl1(self):
        setRe4Stkl(2500000, 1)
        m.lst2017()
        self.assertAlmostEqual(output.lstlzz, 251100, delta=200)

    def test_stkl2(self):
        setRe4Stkl(2500000, 2)
        m.lst2017()
        self.assertAlmostEqual(output.lstlzz, 202500, delta=200)

    def test_stkl3(self):
        setRe4Stkl(2500000, 3)
        m.lst2017()
        self.assertAlmostEqual(output.lstlzz, 25600, delta=200)

    def test_stkl4(self):
        setRe4Stkl(2500000, 4)
        m.lst2017()
        self.assertAlmostEqual(output.lstlzz, 251100, delta=200)

    def test_stkl5(self):
        setRe4Stkl(2500000, 5)
        m.lst2017()
        self.assertAlmostEqual(output.lstlzz, 534000, delta=200)

    def test_stkl6(self):
        setRe4Stkl(2500000, 6)
        m.lst2017()
        self.assertAlmostEqual(output.lstlzz, 571600, delta=200)