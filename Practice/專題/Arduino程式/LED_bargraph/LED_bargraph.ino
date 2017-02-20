int a[3]={5,7,9};
int count=0;
void setup() {
  // put your setup code here, to run once:
  for(int i=0;i<3;i++)
    pinMode(a[i],OUTPUT);
  
  
  
}

void loop() {
  // put your main code here, to run repeatedly:
  int delta=1;
  if(count==-1)
  {
      delta=1;
      count=1;
  }
  else if(count==3)
  {
      delta=-1;
      count=1;
  }
  for(;count>=0&&count<=2;count=count+delta)
  {
    for(int i=0;i<3;i++)
    {
      if(i!=count)
        digitalWrite(a[i],LOW);
       else
        digitalWrite(a[i],HIGH);
    }
    delay(250);
  }
  
 
  
}
