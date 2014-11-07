

#include <CapacitiveSensor.h>// CapacitiveSensor Library.
#define speaker 11


// Set Pin de entrada y pin de salida
CapacitiveSensor   cs_2_3 = CapacitiveSensor(2,3);  // Con una resistencia de 1M entre estas conecciones
CapacitiveSensor   cs_2_4 = CapacitiveSensor(2,4);        
CapacitiveSensor   cs_2_5 = CapacitiveSensor(2,5);        
CapacitiveSensor   cs_2_6 = CapacitiveSensor(2,6);        
CapacitiveSensor   cs_2_7 = CapacitiveSensor(2,7);        
CapacitiveSensor   cs_2_8 = CapacitiveSensor(2,8);       
CapacitiveSensor   cs_2_9 = CapacitiveSensor(2,9);        


void setup()                    
{
  cs_2_3.set_CS_AutocaL_Millis(0xFFFFFFFF); // Ejemplo
  
  // Arduino Se conecta a la PC
  Serial.begin(9600);
}

void loop()                    
{
  // Timer
  long start = millis();
  
  // Sensibilidad de los sensores
  long total1 =  cs_2_3.capacitiveSensor(60);
  long total2 =  cs_2_4.capacitiveSensor(60);
  long total3 =  cs_2_5.capacitiveSensor(60);
  long total4 =  cs_2_6.capacitiveSensor(60);
  long total5 =  cs_2_7.capacitiveSensor(60);
  long total6 =  cs_2_8.capacitiveSensor(60);
  long total7 =  cs_2_9.capacitiveSensor(60);
  


 Serial.print(millis() - start);        // check on performance in milliseconds
  Serial.print("\t");                  
  // Prints para saber cuanta "energia" estan recibiendo los sensores
  Serial.print(total1);                  // print sensor output 1
  Serial.print("\t");                    
  Serial.print(total2);                  // print sensor output 2
  Serial.print("\t");                    
  Serial.print(total3);                  // print sensor output 3
  Serial.print("\t");                    
  Serial.print(total4);                  // print sensor output 4
  Serial.print("\t");                    
  Serial.print(total5);                  // print sensor output 5
  Serial.print("\t");                    
  Serial.print(total6);                  // print sensor output 6
  Serial.print("\t");                    
  Serial.println(total7);                // print sensor output 7
                                         
  
  
  
  
  // Cuando la mano toca el sensor este suena, depende de cuanta energia, se le puede cambiar
  if (total1 > 300) tone(speaker,523); // 523 1047
  if (total2 > 300) tone(speaker,587); // 587 1175
  if (total3 > 300) tone(speaker,659); // 659 1319
  if (total4 > 300) tone(speaker,698); // 698 1397
  if (total5 > 300) tone(speaker,784); // 784 1568
  if (total6 > 300) tone(speaker,880); // 880 1760
  if (total7 > 300) tone(speaker,988); // 988 1976
  
  // Cuando no hay tacto en los sensores
  if (total1<=300  &  total2<=300  &  total3<=300 & total4<=300  &  total5<=300  &  total6<=300 &  total7<=300)
    noTone(speaker);

  delay(0);    // Deay arbitrario
}
