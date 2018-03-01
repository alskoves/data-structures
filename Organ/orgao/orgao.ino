const int C  = 13; //pino 13 é a nota dó
const int D  = 12; //pino 12 é a nota ré
const int E  = 11; //pino 11 é a nota mi
const int F  = 10; //pino 10 é a nota fá 
const int G  =  9; //pino 9 é a nota sol
const int A  =  8; //pino 8 é a nota lá
const int B  =  7; //pino 7 é a nota si
const int CC =  6; //pino 6 é o dó +1 oitava
const int DD =  5; //pino 5 é o ré +1 oitava
const int EE =  4; //pino 4 é o mi +1 oitava

const int freq =  3; // 9 é o pino da frequência que será tocada

void setup() {
  pinMode(C ,  INPUT);
  pinMode(D ,  INPUT);
  pinMode(E ,  INPUT);
  pinMode(F ,  INPUT);
  pinMode(G ,  INPUT);
  pinMode(A ,  INPUT);
  pinMode(B ,  INPUT);
  pinMode(CC,  INPUT);
  pinMode(DD,  INPUT);
  pinMode(EE,  INPUT);
  pinMode(freq, OUTPUT);
}

void loop() {
  if      ( LOW == digitalRead( C ))
      tone( freq , 264 );              //Se o botão estiver apertado, o pino do auto-falante terá a frequência correspondente à nota dó
  else if ( LOW == digitalRead( D ))
      tone( freq , 297 );              //Se o botão estiver apertado, o pino do auto-falante terá a frequência correspondente à nota ré
  else if ( LOW == digitalRead( E ))
      tone( freq , 330 );              //Se o botão estiver apertado, o pino do auto-falante terá a frequência correspondente à nota mi
  else if ( LOW == digitalRead( F ))
      tone( freq , 352 );              //Se o botão estiver apertado, o pino do auto-falante terá a frequência correspondente à nota fá
  else if ( LOW == digitalRead( G ))
      tone( freq , 396 );              //Se o botão estiver apertado, o pino do auto-falante terá a frequência correspondente à nota sol
  else if ( LOW == digitalRead( A ))
      tone( freq , 440 );              //Se o botão estiver apertado, o pino do auto-falante terá a frequência correspondente à nota lá
  else if ( LOW == digitalRead( B ))
      tone( freq , 495 );              //Se o botão estiver apertado, o pino do auto-falante terá a frequência correspondente à nota si
  else if ( LOW == digitalRead( CC))
      tone( freq , 528 );              //Se o botão estiver apertado, o pino do auto-falante terá a frequência correspondente à nota dó
  else if ( LOW == digitalRead( DD))
      tone( freq , 594 );              //Se o botão estiver apertado, o pino do auto-falante terá a frequência correspondente à nota ré
  else if ( LOW == digitalRead( EE))
      tone( freq , 660 );              //Se o botão estiver apertado, o pino do auto-falante terá a frequência correspondente à nota mi
  else
      noTone( freq );                  //Se for qualquer outra coisa, ou seja, nenhum botão estiver apertado, ele não terá nenhuma frequência no autofalante
}

