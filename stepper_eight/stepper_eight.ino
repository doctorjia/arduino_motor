//步进机每个n秒转一圈的程序:

//定义引脚
int Pin0 = 10;
int Pin1 = 11;
int Pin2 = 12;
int Pin3 = 13;

int _step = 0;

boolean dir = false;//正反转
//===============================
int stepperSpeed = 5;//电机转速,n ms一步
//===============================
//脉冲总数，或者说步的总数
int stepsum=0;
void setup()

{
  pinMode(Pin0,OUTPUT);
  pinMode(Pin1,OUTPUT);
  pinMode(Pin2,OUTPUT);
  pinMode(Pin3,OUTPUT);
}


void loop()
{
//进步机的驱动方式，有八种
switch(_step){
    case 0://******************AB
      digitalWrite(Pin0, HIGH);
      digitalWrite(Pin1, HIGH);
      digitalWrite(Pin2, LOW);
      digitalWrite(Pin3, LOW);
    break;
    case 1://******************B
      digitalWrite(Pin0, LOW);
      digitalWrite(Pin1, HIGH);
      digitalWrite(Pin2, LOW);
      digitalWrite(Pin3, LOW);
    break;

    case 2://******************BC
      digitalWrite(Pin0, LOW);
      digitalWrite(Pin1, HIGH);
      digitalWrite(Pin2, HIGH);
      digitalWrite(Pin3, LOW);
    break;

    case 3://******************C
      digitalWrite(Pin0, LOW);
      digitalWrite(Pin1, LOW);
      digitalWrite(Pin2, HIGH);
      digitalWrite(Pin3, LOW);
    break;

    case 4://******************CD
      digitalWrite(Pin0, LOW);
      digitalWrite(Pin1, LOW);
      digitalWrite(Pin2, HIGH);
      digitalWrite(Pin3, HIGH);
    break;

    case 5://******************D
      digitalWrite(Pin0, LOW);
      digitalWrite(Pin1, LOW);
      digitalWrite(Pin2, LOW);
      digitalWrite(Pin3, HIGH);
    break;

    case 6://******************DA
      digitalWrite(Pin0, HIGH);
      digitalWrite(Pin1, LOW);
      digitalWrite(Pin2, LOW);
      digitalWrite(Pin3, HIGH);
    break;

    case 7://******************A
      digitalWrite(Pin0, HIGH);
      digitalWrite(Pin1, LOW);
      digitalWrite(Pin2, LOW);
      digitalWrite(Pin3, LOW);
    break;

    default:
      digitalWrite(Pin0, LOW);
      digitalWrite(Pin1, LOW);
      digitalWrite(Pin2, LOW);
      digitalWrite(Pin3, LOW);
    break;
  }

//判断是正转还是反转
  if(dir)
  {
    _step++;
  }
  else
  {
    _step--;
  }

//每八步一个驱动方式的循环
  if(_step>7)
  {
    _step=0;
  }

  if(_step<0)
  {
    _step=7;
  }
  
  delay(stepperSpeed);

//计算脉冲数，每4096个脉冲停1秒
  stepsum++;
  if(stepsum==4096)
  {
    Serial.println(stepsum);
    stepsum=0;
    delay(1000);
  }

}
