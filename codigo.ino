const int botao1 = 2;
const int botao2 = 3;
const int ledVerde = 8;
const int ledVermelho = 9;

bool estadoAnteriorBotao1 = LOW;
bool estadoAnteriorBotao2 = LOW;

void setup() {
  pinMode(botao1, INPUT);
  pinMode(botao2, INPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  bool estadoAtualBotao1 = digitalRead(botao1);
  bool estadoAtualBotao2 = digitalRead(botao2);

  // Detecta o clique no botão 1
  if (estadoAtualBotao1 == HIGH && estadoAnteriorBotao1 == LOW) {
    simularTag("A123");
  }

  // Detecta o clique no botão 2
  if (estadoAtualBotao2 == HIGH && estadoAnteriorBotao2 == LOW) {
    simularTag("B456");
  }

  estadoAnteriorBotao1 = estadoAtualBotao1;
  estadoAnteriorBotao2 = estadoAtualBotao2;

  delay(50);
}

void simularTag(String tagID) {
  Serial.println("Tag lida: " + tagID);
  if (tagID == "A123") {
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledVermelho, LOW);
    Serial.println("Acesso permitido.");
  } else {
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledVermelho, HIGH);
    Serial.println("Acesso negado.");
  }

  delay(2000);
  digitalWrite(ledVerde, LOW);
  digitalWrite(ledVermelho, LOW);
}
