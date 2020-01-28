 #include <LiquidCrystal.h>
const int waterSens = A0; //definir la valeur du capteur de niveau d'eau.
const int ledR = 7;//led rouge sur le pin 9
const int ledJ =8;// led jaune sur le pin 5
int waterVal; //Pour stocker la valeur du niveau d'eau reçue par le capteur
int buzzer = 9;// le buzzer sur le pin 13 de Arduino

LiquidCrystal lcd(12,11,5,4,3,2);//Création de l'objet écran

void setup() {
pinMode(ledR, OUTPUT); //Definir la ledR sur une sortie/output
pinMode(ledJ, OUTPUT); //Definir la ledJ sur une sortie/output
pinMode(waterSens, INPUT);//Definir le capteur de niveau d'eau comme entree/input
pinMode(buzzer, OUTPUT);//Definir le buzzer en tant que sortie/output
Serial.begin(9600);  //initialisation de la vitesse du port serie a 9600 bauds
lcd.begin(16,2);//on initialise la communication au lcd avec 16 colonnes et deux lignes

Serial.println("Date & Temps, Quantité d'eau en mlc");
}
void loop() {
  waterVal = analogRead(waterSens); //on lit la valeur du lcd puis on la stock dans waterVal 
 nivEau(); //Affichage du niveau d'eau.
}
//Fonction de niveau d'eau 
void nivEau(){
     if(waterVal > 250){
      lcd.setCursor(0,0);
      lcd.print("Jardin");//on affiche Jardin sur l'ecran lcd 
      delay(2000);//apres deux secondes,
      lcd.setCursor(0,1); //on place le curseur a la premiere cologne de la deuxieme ligne du lcd
      lcd.print("Niveau :");
      lcd.setCursor(9,1);
      lcd.print(waterVal);//on affiche le niveau d'eau sur l'ecran lcd
      lcd.setCursor(13,1);//on passe a la neuvieme cologne de la deuxieme ligne lcd
      lcd.print("mlc");//on affiche millilitre cube
      Serial.println(waterVal); //print the value of the water sensor to the serial monitor
      digitalWrite(ledJ, HIGH);//on allume la ledR
      digitalWrite(ledR, LOW);//on eteind la ledJ
      noTone(buzzer);//on eteind le buzzer
      delay(1000);//attend 1sec
    }else
      lcd.setCursor(0,0);
      lcd.print("Jardin");//on affiche Jardin sur l'ecran lcd 
      delay(2000);//apres deux secondes,
      lcd.setCursor(0,1); //on place le curseur a la premiere cologne de la deuxieme ligne du lcd
      lcd.print("Niveau :");
      lcd.setCursor(9,1);
      lcd.print(waterVal);//on affiche le niveau d'eau sur l'ecran lcd
      lcd.setCursor(13,1);//on passe a la neuvieme cologne de la deuxieme ligne lcd
      lcd.print("mlc");//on affiche millilitre cube
       Serial.println(waterVal); //print the value of the water sensor to the serial monitor
          digitalWrite(ledR, HIGH);
          digitalWrite(ledJ, LOW);
          tone(buzzer,300,1000);
          delay(1000);
    }
