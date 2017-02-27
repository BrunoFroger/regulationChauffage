


void setupSerie(){
  Serial.begin(38400);
  Serial.println("");
  Serial.println("Serial Initialised");
}


String serieRead(){
  char tmp[100]="";
  int i=0;
  char car;
  while(Serial.available() > 0){
    car = Serial.read();
    //Serial.write(car);
    tmp[i++]=car;
    tmp[i]=0;
  }
  //Serial.print("serieRead : <");
  //Serial.print(tmp);
  //Serial.println(">");
  return tmp;
}

