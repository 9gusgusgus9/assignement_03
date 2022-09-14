package com.example.garden_app.Bluetooth;

import android.annotation.SuppressLint;
import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.bluetooth.BluetoothManager;
import android.content.Intent;
import android.util.Log;

import com.example.garden_app.MainActivity;

import java.util.ArrayList;
import java.util.Set;

public class BluetoothControlManager {
    private MainActivity activity;
    private static int REQUEST_ENABLE_BT = 1;
    private static String TAG = "Bluetooth status";
    private BluetoothAdapter adapter;
    private ConnectThreadClient connectThreadClient;
    private BluetoothTransferData bluetoothTransferData;
    private int flag;

    public BluetoothControlManager(MainActivity activity){
        this.activity = activity;
        this.adapter = this.activity.getSystemService(BluetoothManager.class).getAdapter();
    }
    @SuppressLint("MissingPermission")
    public void setUpBluetooth() {
        if (adapter == null) {
            Log.e("BluetoothConnection", "The device don't support bluetooth");
        } else {
            if (!adapter.isEnabled()) {
                Intent intent = new Intent(BluetoothAdapter.ACTION_REQUEST_ENABLE);
                activity.startActivityForResult(intent, REQUEST_ENABLE_BT);
            }
        }
        Log.i(TAG, "setting up bluetooth");
    }
    @SuppressLint("MissingPermission")
    public ArrayList<String> getDevicesAlreadyPaired(){
        Set<BluetoothDevice> devices = adapter.getBondedDevices();
        ArrayList<String> list = new ArrayList<>();
        for(BluetoothDevice btd : devices){
            System.out.println(btd.getName());
            if(btd.getName().equals("isi00")){
                list.add(btd.getName() + "\n" + btd.getAddress());
            }
        }
        if (adapter.isDiscovering()){
            adapter.cancelDiscovery();
        }
        adapter.startDiscovery();
        Log.i(TAG, "Get paired device");
        return list;
    }

    public void connectToDevice(String address){
        BluetoothDevice btd = adapter.getRemoteDevice(address);
        connectThreadClient = new ConnectThreadClient(btd, adapter);
        connectThreadClient.start();
    }

    public void transferData(){
        bluetoothTransferData = new BluetoothTransferData(connectThreadClient.getSocket(), this);
        bluetoothTransferData.start();
        bluetoothTransferData.write(activity.getMessage());
    }

    public void getDataFromBluetooth(String data){
        activity.updateValue(data);
    }

    public void disconnectBluetoothConnection(){
        connectThreadClient.cancel();
    }
}
