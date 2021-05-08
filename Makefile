AppName = "Turn Off Xbox 360 Controller.exe"

all: build install clean
build:
	windres XBoxOff.rc -o res.o
	g++ -O2 -c main.cpp -o main.o
	g++ -O2 -Wl,-subsystem,windows -o $(AppName) main.o res.o xinput1_3.dll
	strip $(AppName)
install:
	mkdir -p bin
	mv ./$(AppName) ./bin/
clean:
	rm -f ./*.o ./*.exe
