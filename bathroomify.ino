int magnet=D0;
int RED=A2;

// State
// 0 = Available
// 1 = Occupied
int state;
int last_state = state;




void setup()
{
    pinMode(LED, OUTPUT);
    pinMode(magnet, INPUT_PULLDOWN);

    char *version = "0.0.4";
    Spark.variable("version", version, STRING);

    state = digitalRead(magnet);
    Spark.variable("state", &state, INT);
    Spark.publish("door", (state ? "closed" : "opened"), 60, PRIVATE);

}

void loop()
{
    state = digitalRead(magnet);

    if (state != last_state) {
        digitalWrite(LED, state);
        Spark.publish("door", (state ? "closed" : "opened"), 60, PRIVATE);
    }

    last_state = state;
}



