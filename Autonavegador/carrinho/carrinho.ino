const int trig = 2; /* pino 2 é o trigger dos ultrassons */

const int echofrnt = A0; /* pino A0 é o echo do ultrassom da frente */
const int echosqrd = A1; /* pino A1 é o echo do ultrassom da esquerda */
const int echodirt = A2; /* pino A2 é o echo do ultrassom da direita */

const int mrite  = 9 ; /* pino 9  é o controle do motor da direita;  quando em HIGH, ele gira para frente, quando em LOW, para trás */
const int amrite = 12; /* pino 12 é o mrite reverso */
const int mleft  = 11; /* pino 11 é o controle do motor da esquerda; quando em HIGH, ele gira para frente, quando em LOW, para trás */
const int amleft = 10; /* pino 10 é o mleft reverso */

const int limiarfrnt = 4; /* limiar da distância, ou seja, a quantos centímetros o sensor deve estar de uma parede pra que o carro vire ; limiar do sensor da frente */
const int limiarside = 6; /* limiar da distância, ou seja, a quantos centímetros o sensor deve estar de uma parede pra que o carro vire ; limiar dos sensores laterais */

int direcao = 0; /*
Essa variável vai ser como o programa vai saber que o carro está indo pra frente
Quando está em zero, ele está indo pra frente;
Como vai poder ser visto mais adiante no código,
Quando o carro vira pra direita, essa variável é incrementada;
Quando o carro vira pra esquerda, essa variável é decrementada;
Quando a variável for igual ou menor que zero, ele vai virar pra direita;
Quando a variável for maior que zero, ele vai virar pra esquerda;
Afinal, o propósito do carro vai ser desviar dos obstáculos e seguir sempre em frente
Como observado, a tendência do bicho é sempre virar primeiro pra direita, e vai ser assim porque eu quero
*/

int fodirt = 0; /* flag de obstáculo à direita */

int fosqrd = 0; /* flag de obstáculo A esquerda */

int fofrnt = 0; /* flag de obstáculo à frente */ 

void setup() {
  pinMode(echofrnt, INPUT);
  pinMode(echosqrd, INPUT);
  pinMode(echodirt, INPUT);
  pinMode(trig, OUTPUT);
  pinMode(mrite, OUTPUT);
  pinMode(mleft, OUTPUT);
  pinMode(amrite, OUTPUT);
  pinMode(amleft, OUTPUT);
  delay(1000);
}

void Versens();   /* Lê os sensores de obstáculo */
void Virasqrd();  /* Vira à esquerda */
void Virasqd2();  /* Vira à esquerda duas vezes */
void Viradirt();  /* Vira à direita */
void Viradir2();  /* Vira à direita duas vezes */
void Parafrnt();  /* Segue em frente */

void loop() {  
  Versens();
  if      ( direcao  > 0 &&  fosqrd && !fofrnt)            { Parafrnt(); } /* Se ele virou para a direita, tem algo à esquerda e nada à frente, ele segue em frente */
  else if ( direcao  > 0 &&  fosqrd &&  fofrnt)            { Virasqd2(); } /* Se ele virou para a direita e está impedido pela frente e pela esquerda, ele dá meia volta */ 
  else if ( direcao  > 0 && !fosqrd)                       { Virasqrd(); } /* Se ele virou para a direita e não tem nenhum obstáculo à esquerda, ele vira à esquerda */
  else if ( direcao  < 0 && !fodirt)                       { Viradirt(); } /* Se ele virou para a esquerda e não tem nada à direita, ele vira à direita */ 
  else if ( direcao  < 0 &&  fodirt && !fofrnt)            { Parafrnt(); } /* Se ele virou para a esquerda está impedido somente pela direita, ele segue em frente */
  else if ( direcao  < 0 &&  fodirt &&  fofrnt)            { Viradir2(); } /* Se ele virou para a esquerda e está impedido pela frente e pela direita, ele dá meia volta */ 
  else if ( direcao == 0 && !fofrnt)                       { Parafrnt(); } /* Se ele está indo para frente e não tem nada à frente, ele segue em frente */
  else if ( direcao == 0 && !fodirt && !fosqrd &&  fofrnt) { Viradirt(); } /* Se ele está indo para frente, tem algo à frente e nada à direita, ele vira à direita */ 
  else if ( direcao == 0 &&  fodirt && !fosqrd &&  fofrnt) { Virasqrd(); } /* Se ele está indo para frente, tem algo e frente e algo à direita, ele vira à esquerda */
  else if ( direcao == 0 &&  fodirt &&  fosqrd &&  fofrnt) { Viradir2(); } /* Se ele está indo para frente e está cercado por todos os lados, ele dá meia volta */
}

void Versens(){
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  int tempofrnt= pulseIn(echofrnt, HIGH);
  int temposqrd= pulseIn(echosqrd, HIGH);
  int tempodirt= pulseIn(echodirt, HIGH); 
  double distancefrnt = tempofrnt * 0.017; /* conversão de tempo em centímetros através da velocidade do som (!) */
  double distancesqrd = temposqrd * 0.017;
  double distancedirt = tempodirt * 0.017;
  if      ( distancefrnt <= limiarfrnt ) { fofrnt = 1; }
  else if ( distancesqrd <= limiarside ) { fosqrd = 1; }
  else if ( distancedirt <= limiarside ) { fodirt = 1; }
  else if ( distancefrnt >  limiarfrnt ) { fofrnt = 0; }
  else if ( distancesqrd >  limiarside ) { fosqrd = 0; }
  else if ( distancedirt >  limiarside ) { fodirt = 0; }
}
void Virasqrd(){
  digitalWrite(mleft, LOW);
  digitalWrite(mrite, HIGH);
  digitalWrite(amleft, HIGH);
  digitalWrite(amrite, LOW);
  direcao--;
  delay(1000);
}
void Virasqd2(){
  Virasqrd();
  Virasqrd();
}
void Viradirt(){
  digitalWrite(mleft, HIGH);
  digitalWrite(mrite, LOW);
  digitalWrite(amleft, LOW);
  digitalWrite(amrite, HIGH);
  direcao++;
  delay(1000);
}
void Viradir2(){
  Viradirt();
  Viradirt();
}
void Parafrnt(){
  digitalWrite(mleft, HIGH);
  digitalWrite(mrite, HIGH);
  digitalWrite(amleft, LOW);
  digitalWrite(amrite, LOW);
  direcao=direcao;
}

