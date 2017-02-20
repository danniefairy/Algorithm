int a[3]={5,7,9};
int count=0;
int delta=1;
void setup() {
  // put your setup code here, to run once:
  for(int i=0;i<3;i++)
  {
    pinMode(a[i],OUTPUT);
    digitalWrite(a[i],LOW);
  }
  
  
}

void loop() {
  // put your main code here, to run repeatedly:
 
  if(count==-1)
  {
      delta=1;
      count=0;
  }
  else if(count==3)
  {
      delta=-1;
      count=2;
  }


    digitalWrite(a[count],HIGH);
    digitalWrite(a[count-delta],LOW);
    if(count==0||count==2)
      delay(125);
    else
      delay(250);
    count=count+delta; 
  
}
