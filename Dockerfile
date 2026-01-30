FROM gcc:latest

WORKDIR /usr/src/app

COPY . .

RUN gcc -o SimulatorInvestitiiFinanciare src/main.c src/finance.c src/utils.c -lm

CMD ["./SimulatorInvestitiiFinanciare", "--help"]