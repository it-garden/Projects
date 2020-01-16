void setup() {
  Serial.begin(200000);
}

void loop() {
  if (Serial.available()) {
    String espD = Serial.readString();
    int i;
    if (-1 != (i = espD.indexOf("RGB"))) {
      byte r = strtol(espD.substring(i+3, i+5).c_str(), nullptr, 16);
      byte g = strtol(espD.substring(i+5, i+7).c_str(), nullptr, 16);
      byte b = strtol(espD.substring(i+7, i+9).c_str(), nullptr, 16);
      Serial.write("RGB: #");
      Serial.write(espD.substring(i+3, i+9).c_str());
      Serial.println();
      analogWrite(11, r);
      analogWrite(10, g);
      analogWrite(9, b);
    } 
    if (-1 != (i = espD.indexOf("FAN"))) {
      byte pwr = strtol(espD.substring(i+3, i+5).c_str(), nullptr, 16);
      Serial.write("FAN: ");
      Serial.println(pwr);
      analogWrite(3, pwr);
    }
  }
}
