# sc_steuer

## Build, Generate, Execute

1. Configure CBMC path in sc_steuer/build, sc_steuer/Client/run and sc_steuer/Server/run
2. Execute ./build in sc_steuer to build the circuit

### Generate Input Tests and Execute Test

1. Configure getInputs() in test/main.py
2. Execute test/main.py [cbmc directory] i.e.: "python3 test/main.py /home/user/cbmc-gc-v0.9.3/"
3. Read output ☺