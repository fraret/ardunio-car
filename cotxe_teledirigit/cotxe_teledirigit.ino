
/* GPL v3 fraret 
 * 2015-2016
 * 
 * Aquest codi font (escrit per ser compilat per a Arduino) serveix per 
 * controlar dos actuadors (transistors, LEDs, reles...) per mitja d'un
 * commandament d'IR (rajos infrarrojos).
 *
 * NO HAURIA DE SER NECESSARI MODIFICAR AQUEST FITXER PER TAL DE 
 * FER FUNCIONAR EL COMANDAMENT D'IR
 */
#include <IRremote.h>
#include "codis.h"

int c = 0;  //contador

//necessari per que funcioni el IR:
IRrecv irrecv(RECV_PIN);

decode_results results;




void setup()
{
  irrecv.enableIRIn(); //iniciar sensor IR
  pinMode(LT_MOTOR, OUTPUT); 
  digitalWrite(LT_MOTOR, LOW); 
  pinMode(RT_MOTOR, OUTPUT); 
  digitalWrite(RT_MOTOR, LOW); 
  delay(200); //
}

void loop()
{
  if (irrecv.decode(&results)) {
    c = 0; //si rep alguna senyal, el contador de cicles sense senyal torna a zero
    switch (results.value) { //tria la opcio que coincideixi amb el codi redut, si no executa la opcio "default"
      case CODE_LT: 
        digitalWrite(RT_MOTOR, HIGH); //engega el motor dret per tal de que el cotxe giri cap a l'esquerra
        delay(100);
        break;
      case CODE_RT: //engega el motor esquerre per tal de que el cotxe giri cap a la dreta
       digitalWrite(LT_MOTOR, HIGH);
       delay(100);
        break;
      case CODE_FW: //engega els dos motors, per fer que el cotxe es mogui endavant
      digitalWrite(LT_MOTOR, HIGH);
      digitalWrite(RT_MOTOR, HIGH);
        delay(100);
        break;
      case CODE_REPEAT: 
        break; //si rep el codi de repeticio no fa res, ni apaga ni engega
      default:
        digitalWrite(LT_MOTOR, LOW);
        digitalWrite(RT_MOTOR, LOW); // si rep algun altre codi apaga els motors
        break;
    }
    irrecv.resume();
  }
  else { //si no rep senyal, espera CICLES cicles, perque el IR no pot rebre i descodificar una senyal cada cicle
    c = c + 1;
    if(c > CICLES){ //si al cap de CICLES cicles no capta cap codi, apaga els dos motors
      digitalWrite(LT_MOTOR, LOW);
      digitalWrite(RT_MOTOR, LOW);
    }
  }
}





