package com.example.garden_app.Bluetooth;

import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothServerSocket;
import android.bluetooth.BluetoothSocket;

import java.io.IOException;
import java.util.UUID;

public class ConnectThreadServer extends Thread{
    public static final String NAME = "device";
    private static final UUID MY_UUID = UUID.fromString("00001101-0000-1000-8000-00805F9B34FB");
    private static final String TAG = "Error Occured";
    private BluetoothServerSocket socket;
    private BluetoothAdapter adapter;

    public ConnectThreadServer(BluetoothAdapter adpt){
        adapter = adpt;
        BluetoothServerSocket tmp = null;
        try {
            tmp = adapter.listenUsingRfcommWithServiceRecord(NAME, MY_UUID);
        } catch (IOException e) {
            e.printStackTrace();
        }
        socket = tmp;
    }

    @Override
    public void run() {
        BluetoothSocket socketTmp = null;
        while (true){
            try {
                socketTmp = this.socket.accept();
            } catch (IOException e) {
                e.printStackTrace();
            }

            if (socket != null){
                try {
                    socket.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                break;
            }
        }
    }

    public void cancel(){
        try {
            socket.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
