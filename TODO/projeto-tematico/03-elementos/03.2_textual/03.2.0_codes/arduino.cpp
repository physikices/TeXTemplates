int sensorSUP = 12;
int sensorINF = 11;
int estadoSUP;
unsigned long startTime;
unsigned long stopTime;
void setup(){
    Serial.begin(9600);
    pinMode (sensorSUP, INPUT);
    pinMode (sensorINF, INPUT);
    estadoSUP = 1 ;
    Serial.println("Pronto para medir o tempo de queda");
    Serial.println(" ");
}
void loop(){
    if(digitalRead(sensorSUP) == LOW && (digitalRead(sensorINF)) == LOW && estadoSUP == 1){
        startTime = millis();
        Serial.print(" Inicio da medida ---");
        Serial.print("Esfera caindo... Contanto tempo...");
        estadoSUP = 0;
    }
    
    if(digitalRead(sensorINF) == HIGH && (digitalRead(sensorSUP)) == LOW){
        estadoSUP = 1;
        stopTime = ( millis() - startTime);
        Serial.print("Tempo de queda = ");
        Serial.print(stopTime);
        Serial.print(" milisegundos (ms)|Aguarde 10 segundos...");
        delay(10000);
        Serial.println("Pronto para proxima medida");
    }
}