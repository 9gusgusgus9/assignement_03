package com.example.garden_app;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;
import androidx.constraintlayout.widget.ConstraintLayout;

import android.content.DialogInterface;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.ImageButton;
import android.widget.ScrollView;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    private int led3Val;
    private int led4Val;
    private int irrigationVal;
    private Status currentMode;

    private Button auto;
    private Button manual;
    private ImageButton alarm;
    private TextView status;

    private ScrollView scrollView;
    private ConstraintLayout constraintLayout;
    private Button led1;
    private Button led2;
    private ImageButton led3Meno;
    private ImageButton led3Piu;
    private TextView infoLed3;
    private ImageButton led4Piu;
    private ImageButton led4Meno;
    private TextView infoLed4;
    private TextView infoIrragation;
    private Button irrigation;
    private ImageButton irrigationPiu;
    private ImageButton irrigationMeno;



    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        currentMode = Status.Alarm;
        if(this != null){
            Utilities.setUpToolBar(this, "Smart Garden");
        }

        constraintLayout = findViewById(R.id.constraintLayoutFirst);
        auto = findViewById(R.id.button_auto);
        manual = findViewById(R.id.button_manual);
        alarm = findViewById(R.id.button_alarm);
        status = findViewById(R.id.text_status);
        scrollView = findViewById(R.id.scrollView);
        led1 = findViewById(R.id.led1_OnOff);
        led2 = findViewById(R.id.led2_OnOff);
        led3Piu = findViewById(R.id.led3_piu);
        led3Meno = findViewById(R.id.led3_meno);
        infoLed3 = findViewById(R.id.led3_info);
        led4Piu = findViewById(R.id.led4_piu);
        led4Meno = findViewById(R.id.led4_meno);
        infoLed4 = findViewById(R.id.led4_info);
        infoIrragation = findViewById(R.id.irrigationInfo);
        irrigation = findViewById(R.id.irrigationButton);
        irrigationPiu = findViewById(R.id.irrigationPiu);
        irrigationMeno = findViewById(R.id.irrigationMeno);
        constraintLayout.setVisibility(View.INVISIBLE);

        auto.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                setAutoMode();
            }
        });

        manual.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                setManualMode();
            }
        });

        alarm.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                status.setText("ALARM DEACTIVATE!");
                auto.setVisibility(View.VISIBLE);
            }
        });

    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        getMenuInflater().inflate(R.menu.top_app_bar, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(@NonNull MenuItem item) {
        new AlertDialog.Builder(this).setMessage("Connessione bluetooth effettuata!").setPositiveButton("Ok", new DialogInterface.OnClickListener() {
            @Override
            public void onClick(DialogInterface dialogInterface, int i) {
                if(currentMode == Status.Auto){
                    setAutoMode();
                } else if (currentMode == Status.Alarm){
                    setAlarmMode();
                } else {
                    setManualMode();
                }
            }
        }).show();
        return false;
    }


    private void setManualMode(){
        constraintLayout.setVisibility(View.VISIBLE);
        scrollView.setVisibility(View.VISIBLE);
        currentMode = Status.Manual;
        auto.setVisibility(View.VISIBLE);
        manual.setVisibility(View.INVISIBLE);
        alarm.setVisibility(View.INVISIBLE);
        status.setText("CURRENT: MANUAL MODE");
    }

    private void setAutoMode(){
        constraintLayout.setVisibility(View.VISIBLE);
        scrollView.setVisibility(View.INVISIBLE);
        currentMode = Status.Auto;
        manual.setVisibility(View.VISIBLE);
        auto.setVisibility(View.INVISIBLE);
        alarm.setVisibility(View.INVISIBLE);
        status.setText("CURRENT: AUTO MODE");
    }

    public void setAlarmMode() {
        constraintLayout.setVisibility(View.VISIBLE);
        scrollView.setVisibility(View.INVISIBLE);
        auto.setVisibility(View.INVISIBLE);
        alarm.setVisibility(View.VISIBLE);
        status.setText("ALARM MODE!!");
        manual.setVisibility(View.INVISIBLE);
    }
}
