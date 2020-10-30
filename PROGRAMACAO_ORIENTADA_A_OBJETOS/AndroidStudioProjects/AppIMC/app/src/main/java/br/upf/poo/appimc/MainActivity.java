package br.upf.poo.appimc;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {
    // Atributos para referenciar os componentes visuais
    private EditText editNome;
    private EditText editPeso;
    private EditText editAltura;
    private TextView textResultado;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        // inicializar os atributos com os comp. visuais do XML
        editNome = findViewById(R.id.editNome);
        editPeso = findViewById(R.id.editPeso);
        editAltura = findViewById(R.id.editAltura);
        textResultado = findViewById(R.id.textResultado);
    }

    public void calcular(View v){
        Imc i = new Imc(
                editNome.getText().toString(),
                Float.parseFloat(editPeso.getText().toString()),
                Float.parseFloat(editAltura.getText().toString())
        );

        String res = "Indice: " + i.getIndiceImc() + " " + i.getInterpretacao();
        textResultado.setText(res);
    }

}
