#include <M5StickCPlus.h>

#define DAC_PIN 26  // GPIO26 = DAC1 sur ESP32

int value_adc = 0;
float voltage = 0;
int flipfull = 0;

void setup() {
  M5.begin();  // Initialize the M5StickC-Plus
              
  M5.Lcd.setTextColor(YELLOW);  // Set the font color to yellow
  M5.Lcd.setTextSize(4);  		// Set the font size to 4
  M5.Lcd.setRotation(3);
  M5.Lcd.setTextColor(RED);

  Serial.begin(115200);
  Serial.println("Entrez une valeur entre 0 et 255 pour régler la tension du DAC.");

  M5.Lcd.setTextSize(4);
  M5.Lcd.fillScreen(BLACK);  // Set BLACK to the background color.
  M5.Lcd.setCursor(10, 10);
  M5.Lcd.print("ADC :");
  M5.Lcd.print(value_adc);
  M5.Lcd.println();
  M5.Lcd.print(voltage);
  M5.Lcd.print(" V");
}

void loop() {
  M5.update();  // Read the press state of the key

  if (Serial.available()) {
    String input = Serial.readStringUntil('\n');  // Lire jusqu'à retour chariot
    input.trim();                                 // Supprimer espaces et retour chariot

    if (input.length() > 0) {     // Vérifier qu'il y a une entrée valide
      value_adc = input.toInt();  // Convertir en entier

      if (value_adc >= 0 && value_adc <= 255) {
        dacWrite(DAC_PIN, value_adc);  // Écrire la valeur sur le DAC
        voltage = (value_adc / 255.0) * 3.3;
        Serial.print("Valeur DAC: ");
        Serial.print(value_adc);
        Serial.print(" -> Tension: ");
        Serial.print(voltage, 2);
        Serial.println(" V");
      } else {
        Serial.println("Erreur : entrez une valeur entre 0 et 255 !");
      }
    }
  }

  if (M5.BtnA.wasReleased()) {  // If the button A is pressed

    value_adc = value_adc + 10;  // Convertir en entier

    if (flipfull == 1) {
      value_adc = 0;
      flipfull = 0;
    }

    if (value_adc > 255) {
      value_adc = 255;
      flipfull = 1;
    }



    if (value_adc >= 0 && value_adc <= 255) {
      dacWrite(DAC_PIN, value_adc);  // Écrire la valeur sur le DAC
      voltage = (value_adc / 255.0) * 3.3;
      Serial.print("Valeur DAC: ");
      Serial.print(value_adc);
      Serial.print(" -> Tension: ");
      Serial.print(voltage, 2);
      Serial.println(" V");

      M5.Lcd.setTextSize(4);
      M5.Lcd.fillScreen(BLACK);  // Set BLACK to the background color
      M5.Lcd.setCursor(10, 10);
      M5.Lcd.print("ADC :");
      M5.Lcd.print(value_adc);
      M5.Lcd.println();
      M5.Lcd.print(voltage);
      M5.Lcd.print(" V");
    }
  } else if (M5.BtnB.wasReleased()) {  // If the button B is pressed.
    value_adc = value_adc + 50;        // Convertir en entier

    if (flipfull == 1) {
      value_adc = 0;
      flipfull = 0;
    }

    if (value_adc > 255) {
      value_adc = 255;
      flipfull = 1;
    }

    if (value_adc >= 0 && value_adc <= 255) {
      dacWrite(DAC_PIN, value_adc);  // Écrire la valeur sur le DAC
      voltage = (value_adc / 255.0) * 3.3;
      Serial.print("Valeur DAC: ");
      Serial.print(value_adc);
      Serial.print(" -> Tension: ");
      Serial.print(voltage, 2);
      Serial.println(" V");

      M5.Lcd.setTextSize(4);
      M5.Lcd.fillScreen(BLACK);  // Set BLACK to the background color.
      M5.Lcd.setCursor(10, 10);
      M5.Lcd.print("ADC :");
      M5.Lcd.print(value_adc);
      M5.Lcd.println();
      M5.Lcd.print(voltage);
      M5.Lcd.print(" V");
    }

  } else if (M5.BtnB.wasReleasefor(700)) {  // The button B is pressed for 700ms.
    M5.Lcd.fillScreen(BLACK);               // Set BLACK to the background color.
    M5.Lcd.setCursor(0, 0);
  }
}
