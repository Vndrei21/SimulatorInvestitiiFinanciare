FROM gcc:latest

WORKDIR /usr/src/app

COPY . .

RUN ls -R

RUN gcc -I./src -o SimulatorInvestitiiFinanciare src/main.c src/finance.c src/utils.c -lm

CMD ["./SimulatorInvestitiiFinanciare", "--help"]
