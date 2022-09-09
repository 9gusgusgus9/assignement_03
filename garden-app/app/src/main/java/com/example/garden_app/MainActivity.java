package com.example.garden_app;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;

import android.annotation.SuppressLint;
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

    private Button alarm;
    private Button manualMode;
    private ScrollView scrollView;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        currentMode = Status.Auto;
        if(this != null){
            Utilities.setUpToolBar(this, "Smart Garden");
        }

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
        scrollView = findViewById(R.id.scrollView);

        scrollView.setVisibility(View.INVISIBLE);

    }



    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        getMenuInflater().inflate(R.menu.top_app_bar, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(@NonNull MenuItem item) {
        if (item.getItemId() == R.id.manual) {
            new AlertDialog.Builder(this).setMessage("Vuoi passare alla modalità manuale?").setPositiveButton("Yes", new DialogInterface.OnClickListener() {
                @Override
                public void onClick(DialogInterface dialogInterface, int i) {
                    scrollView.setVisibility(View.VISIBLE);
                }
            }).setNegativeButton("No", new DialogInterface.OnClickListener() {
                @Override
                public void onClick(DialogInterface dialogInterface, int i) {
                    dialogInterface.cancel();
                }
            }).show();
        }
        return false;
    }
}