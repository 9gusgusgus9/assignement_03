package com.example.garden_app;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;
import androidx.constraintlayout.widget.ConstraintLayout;

import android.bluetooth.BluetoothDevice;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.ImageButton;
import android.widget.ListView;
import android.widget.ScrollView;
import android.widget.TextView;

import com.example.garden_app.Bluetooth.BluetoothControlManager;

import java.util.ArrayList;
import java.util.List;

public class MainActivity extends AppCompatActivity {

    private AppCompatActivity activity;

    private int led3Val;
    private int led4Val;
    private int irrigationVal;
    private TextView bluetoothStatus;
    private ListView listView;
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

    private BluetoothControlManager btControlManager;
    private List<String> devices = new ArrayList<>();

    private final BroadcastReceiver receiver = new BroadcastReceiver() {
        @Override
        public void onReceive(Context context, Intent intent) {
            String action = intent.getAction();
            BluetoothDevice device = intent.getParcelableExtra(BluetoothDevice.EXTRA_DEVICE);
            if(BluetoothDevice.ACTION_ACL_CONNECTED.equals(action)){
                bluetoothStatus.setText("Connection OK");
                manual.setVisibility(View.VISIBLE);
            } else if (BluetoothDevice.ACTION_ACL_DISCONNECTED.equals(action)){
                bluetoothStatus.setText("Connection NOT OK");
                auto.setVisibility(View.INVISIBLE);
                manual.setVisibility(View.INVISIBLE);
                scrollView.setVisibility(View.INVISIBLE);
                status.setVisibility(View.INVISIBLE);
            }
        }
    };

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        activity = this;
        currentMode = Status.Auto;
        if(this != null){
            Utilities.setUpToolBar(this, "Smart Garden");
        }
        constraintLayout = findViewById(R.id.constraintLayoutFirst);
        listView = findViewById(R.id.listview);
        bluetoothStatus = findViewById(R.id.bluetooth_status);
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

        this.irrigationVal = 0;
        this.led3Val = 0;
        this.led4Val = 0;

        btControlManager = new BluetoothControlManager(this);

        IntentFilter intentFilter = new IntentFilter();
        intentFilter.addAction(BluetoothDevice.ACTION_ACL_CONNECTED);
        intentFilter.addAction(BluetoothDevice.ACTION_ACL_DISCONNECT_REQUESTED);
        intentFilter.addAction(BluetoothDevice.ACTION_ACL_DISCONNECTED);

        infoLed3.setText(String.valueOf(this.led3Val));
        infoLed4.setText(String.valueOf(this.led4Val));
        infoIrragation.setText(String.valueOf(this.irrigationVal));


        constraintLayout.setVisibility(View.INVISIBLE);

        auto.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                setAutoMode();
                btControlManager.transferData(Code.MODECODE);
            }
        });

        manual.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                setManualMode();
                btControlManager.transferData(Code.MODECODE);
            }
        });

        alarm.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                status.setText("ALARM DEACTIVATE!");
                auto.setVisibility(View.VISIBLE);
                btControlManager.transferData(Code.ALARMCODE);
            }
        });

        led3Piu.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if(led3Val < 5){
                    led3Val++;
                    infoLed3.setText(String.valueOf(led3Val));
                    btControlManager.transferData(Code.LED3PIU);
                }
            }
        });

        led3Meno.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if(led3Val >= 1){
                    led3Val--;
                    infoLed3.setText(String.valueOf(led3Val));
                    btControlManager.transferData(Code.LED3MENO);
                }
            }
        });

        led4Piu.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if(led4Val < 5){
                    led4Val++;
                    infoLed4.setText(String.valueOf(led4Val));
                    btControlManager.transferData(Code.LED4PIU);
                }
            }
        });

        led4Meno.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if(led4Val >= 1){
                    led4Val--;
                    infoLed4.setText(String.valueOf(led4Val));
                    btControlManager.transferData(Code.LED4MENO);
                }
            }
        });

        listView.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> adapterView, View view, int position, long id) {
                String bdrInfo = (String) ((ArrayAdapter) listView.getAdapter()).getItem(position);
                String[] info = bdrInfo.split("\n");
                System.out.println(info[1]);
                btControlManager.connectToDevice(info[1]);
            }
        });

        led1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                btControlManager.transferData(Code.LED1);
            }
        });

        led2.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                btControlManager.transferData(Code.LED2);
            }
        });

        irrigation.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                btControlManager.transferData(Code.IRRIGATION);
            }
        });

        irrigationPiu.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if(irrigationVal < 5){
                    irrigationVal++;
                    infoIrragation.setText(String.valueOf(irrigationVal));
                    btControlManager.transferData(Code.IRRIGATIONPIU);
                }

            }
        });

        irrigationMeno.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if(irrigationVal >= 1){
                    irrigationVal--;
                    infoIrragation.setText(String.valueOf(irrigationVal));
                    btControlManager.transferData(Code.IRRIGATIONMENO);
                }
            }
        });

        this.registerReceiver(receiver, intentFilter);
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        getMenuInflater().inflate(R.menu.top_app_bar, menu);
        return true;
    }

    @Override
    protected void onStop() {
        super.onStop();
        btControlManager.disconnectBluetoothConnection();
    }

    @Override
    public boolean onOptionsItemSelected(@NonNull MenuItem item) {
        super.onOptionsItemSelected(item);
        if(item.getItemId() == R.id.bluetooth){
            btControlManager.setUpBluetooth();
            constraintLayout.setVisibility(View.VISIBLE);
            scrollView.setVisibility(View.INVISIBLE);
            auto.setVisibility(View.INVISIBLE);
            manual.setVisibility(View.INVISIBLE);
            alarm.setVisibility(View.INVISIBLE);
            status.setVisibility(View.INVISIBLE);
            this.bluetoothStatus.setVisibility(View.VISIBLE);
            this.bluetoothStatus.setText("Connection NOT OK");
            this.devices = btControlManager.getDevicesAlreadyPaired();
            this.listView.setAdapter(new ArrayAdapter<String>(this, android.R.layout.simple_list_item_1,devices));
        }

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

    public void updateAlarmStatus(){
        currentMode = Status.Alarm;
        setAlarmMode();
    }

}
