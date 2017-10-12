//Make the basic GUI layout
import processing.serial.*;
import controlP5.*;

ControlP5 jControl;
Serial myPort;
boolean firstContact = false;
String val;
boolean toggleFlag;

//Textlabel LabelA;
Textlabel LabelB;
Textlabel LabelC;
Textlabel LabelD;

//controlP5.Textlabel A;
controlP5.Textlabel IR;
controlP5.Textlabel Pot;
controlP5.Textlabel Ther;
controlP5.Textlabel Slot;
controlP5.Textlabel Push;

controlP5.Textlabel Header;

Textlabel Label_IR;
Textlabel Label_Pot;
Textlabel Label_Ther;
Textlabel Label_Slot;
Textlabel Label_Push;

void setup()
{
  size(600, 600);
  jControl = new ControlP5(this);
  
  PFont font = createFont("arial",20);
  PFont font1 = createFont("arial",15);
  
  String portName = Serial.list()[1];
  myPort = new Serial(this, portName, 9600);
  println("myPortSet");
  myPort.bufferUntil('\n');  //Make sure Arduino always sens Serial.println()
  
  //Header = new Textlabel(jControl, "Team E: Sensors and Motors Lab", 225, 25, 200, 30);
  
  //LabelA = new Textlabel(jControl, "Servo Motor", 50, 130, 40, 30);
  //A = jControl.addTextlabel("label","Servo Motor", 50, 110); 
  //jControl.addButton("Servo_Button", 1, 50, 150, 70, 30);
  jControl.addTextlabel("label_Servo")
          .setText("Servo Motor")
          .setPosition(40, 130)
          .setFont(font1)
          ;
          
  jControl.addTextfield("Servo_input")
     .setPosition(50,150)
     .setSize(70,30)
     .setFont(font)
     .setColor(color(255,0,0))
     .setLabel("")
     ;
  
  LabelB = new Textlabel(jControl, "DC Motor", 250, 130, 40, 30);
  //jControl.addButton("DC_Button_Position", 1, 150, 150, 90, 30);
  //jControl.addButton("DC_Button_Velocity", 1, 150, 200, 90, 30);
  
  jControl.addTextfield("DC_pos_input")
     .setPosition(250,150)
     .setSize(70,30)
     .setFont(font)
     .setColor(color(255,0,0))
     .setLabel("")
     ;
     
  jControl.addTextfield("DC_vel_input")
     .setPosition(250,200)
     .setSize(70,30)
     .setFont(font)
     .setColor(color(255,0,0))
     .setLabel("")
     ;
  
  LabelC = new Textlabel(jControl, "Stepper Motor", 450, 130, 40, 30);
  //jControl.addButton("Stepper_Button", 1, 250, 150, 90, 30);
  jControl.addTextfield("Stepper_input")
     .setPosition(450,150)
     .setSize(70,30)
     .setFont(font)
     .setColor(color(255,0,0))
     .setLabel("")
     ;
  
  LabelD = new Textlabel(jControl, "Sensors", 250, 250, 40, 30);
  //jControl.addButton("IR_Button", 1, 150, 290, 90, 30);
  //jControl.addButton("Pot_Button", 1, 150, 340, 90, 30);
  //jControl.addButton("Thermistor_Button", 1, 150, 390, 90, 30);
  //jControl.addButton("Slot_Button", 1, 150, 440, 90, 30);
  //jControl.addButton("Push_Button", 1, 150, 490, 90, 30);
  
  Label_IR = new Textlabel(jControl, "IR Value", 150, 290, 40, 30);
  Label_Pot = new Textlabel(jControl, "Potentiometer Value", 150, 340, 90, 30);
  Label_Ther = new Textlabel(jControl, "Thermistor Value", 150, 390, 90, 30);
  Label_Slot = new Textlabel(jControl, "Slot Value", 150, 440, 40, 30);
  Label_Push = new Textlabel(jControl, "Push Button Value", 150, 490, 90, 30);
  
  IR = jControl.addTextlabel("label_IR","", 250, 290);
  Pot = jControl.addTextlabel("label_Pot","", 250, 340);
  Ther = jControl.addTextlabel("label_Ther","", 250, 390);
  Slot = jControl.addTextlabel("label_Slot","", 250, 440);
  Push = jControl.addTextlabel("label_Push","", 250, 490);
  
  //jControl.addButton("M/A", 1, 150, 50, 90, 30);
  jControl.addToggle("toggle")
     .setPosition(250,70)
     .setSize(120,30)
     .setValue(true)
     .setMode(ControlP5.SWITCH)
     .setCaptionLabel("Sensor Input      User Input")
     ;
  
  jControl.addTextlabel("label_Header")
          .setText("Team E: Sensors & Motors Lab")
          .setPosition(175, 25)
          .setFont(font)
          ;
}

void draw()
{
  background(0);
  
  stroke(0);
  fill(150);
  rect(40, 125, 90, 70, 7);
  
  //LabelA.draw(this);
  //jControl.getController("label").setStringValue("Servo_changed");
  //jControl.getController("label_IR").setStringValue("IR_value");
  //jControl.getController("label_Pot").setStringValue("Pot_value");
  //jControl.getController("label_Ther").setStringValue("Ther_value");
  //jControl.getController("label_Slot").setStringValue("Slot_Value");
  //jControl.getController("label_Push").setStringValue("Push_value");
  LabelB.draw(this);
  LabelC.draw(this);
  LabelD.draw(this);
  
  Label_IR.draw(this);
  Label_Pot.draw(this);
  Label_Ther.draw(this);
  Label_Slot.draw(this);
  Label_Push.draw(this);
}

public void Servo_input(String theText) {
  // automatically receives results from controller input
  println("a textfield event for controller 'Servo_input' : "+theText);
  //NEED TO CHECK IF THE VALUES ARE VALID
  
  myPort.write(theText);
  //if(toggleFlag)
  //  myPort.write("sa,"+theText);  
  //else
  //  {
  //    if(Integer.parseInt(theText) >= 0 && Integer.parseInt(theText) <= 360)
  //      myPort.write("ua,"+theText);
  //  }
}

public void DC_pos_input(String theText) {
  // automatically receives results from controller input
  println("a textfield event for controller 'DC_pos_input' : "+theText);
  myPort.write(theText);
  //if(toggleFlag)
  //  myPort.write("sb,"+theText);
  //else
  //{
  //  if(Integer.parseInt(theText) >= 0 && Integer.parseInt(theText) <= 360)
  //    myPort.write("ub,"+theText);
  //}
}

public void DC_vel_input(String theText) {
  // automatically receives results from controller input
  println("a textfield event for controller 'DC_vel_input' : "+theText);
  myPort.write(theText);
  //if(toggleFlag)
  //  myPort.write("sc,"+theText);
  //else
  //{  FEASIBLE VELOCITY RANGE? UNITS?
  //  if(Integer.parseInt(theText) >= -100 && Integer.parseInt(theText) <= 100)
  //    myPort.write("uc,"+theText);
  //}
}

public void Stepper_input(String theText) {
  // automatically receives results from controller input
  println("a textfield event for controller 'Stepper_input' : "+theText);
  myPort.write(theText);
  //if(toggleFlag)
  //  myPort.write("sD,"+theText);
  //else
  //{  FEASIBLE RANGE? UNITS?
  //  if(Integer.parseInt(theText) >= 0 && Integer.parseInt(theText) <= 360)
  //    myPort.write("uD,"+theText);
  //}
}

void toggle(boolean theFlag) {
  if(theFlag==true) {
    println("Sensor_Input");
    toggleFlag = theFlag;
  } else {
    println("User_Input");
    toggleFlag = theFlag;
  }
}

void serialEvent(Serial myPort) {
//put the incoming data into a String - 
//the '\n' is our end delimiter indicating the end of a complete packet
//val = null;  //How to make the val stop appending new readings to it??
val = myPort.readStringUntil('\n');
//make sure our data isn't empty before continuing
if (val != null) {
  //trim whitespace and formatting characters (like carriage return)
  val = trim(val);
  //println(val);
  println(val);
  //look for our 'A' string to start the handshake
  //if it's there, clear the buffer, and send a request for data
  if (firstContact == false) {
    if (val.equals("A")) {
      //myPort.clear();
      //firstContact = true;
      //myPort.write("A");
      //println("contact");
    }
  }
  else { //if we've already established contact, keep getting and parsing data
    
    int [] index = new int[4];
    int firstC = 0;
    for(int i=0;i<val.length();i++)
    {
      if(val.charAt(i) == ',')
        {
          index[firstC] = i;
          firstC++;
        }
    }
    String val1 = val.substring(0, index[0]);
    String val2 = val.substring(index[0]+1, index[1]);
    String val3 = val.substring(index[1]+1, index[2]);
    String val4 = val.substring(index[2]+1, index[3]);
    String val5 = val.substring(index[3]+1);
    
    jControl.getController("label_IR").setStringValue(val1);
    jControl.getController("label_Pot").setStringValue(val2);
    jControl.getController("label_Ther").setStringValue(val3);
    jControl.getController("label_Slot").setStringValue(val4);
    jControl.getController("label_Push").setStringValue(val5);
    
    //if(val.equals("z"))
    ////{
    ////  printIR();  Somehow figure out how to take the next value not the current val
    ////}
    //  jControl.getController("label_IR").setStringValue(val);
    //else if(val.equals("b"))
    //  jControl.getController("label_Pot").setStringValue(val);
    //else if(val.equals("c"))
    //  jControl.getController("label_Ther").setStringValue(val);
    //else if(val.equals("d"))
    //  jControl.getController("label_Slot").setStringValue(val);
    //else if(val.equals("e"))
    //  jControl.getController("label_Push").setStringValue(val);
    //if (mousePressed == true) 
    //{                           //if we clicked in the window
    //  myPort.write('1');        //send a 1
    //  println("1");
    //}
    //// when you've parsed the data you have, ask for more:
    //myPort.clear();
    myPort.write("A");
    }
  }
}