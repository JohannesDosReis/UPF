/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package br.upf.poo.prog02.dominio;

import br.upf.poo.uteis.Leitura;

/**
 *
 * @author Johannes Dos Reis
 */
public class ArCondicionado {

    // Atributos
    private boolean ligado;
    private int temperatura;
    private int velocidade;
    private String operacao;
    
    private String name;
    private static int sequence = 1;

    public boolean isLigado() {
        return ligado;
    }

    public boolean getEstado() {
        return ligado;
    }

    public int getTemperatura() {
        return temperatura;
    }

    public int getVelocidade() {
        return velocidade;
    }

    public String getOperacao() {
        return operacao;
    }

    public String getName() {
        return name;
    }
    
    public ArCondicionado() {
        super();
        this.ligado = false;
        this.operacao = "Auto";
        this.temperatura = 22;
        this.velocidade = 1;
        
        this.name = "Ar Condicionado " + sequence++;
    }
    
    public ArCondicionado(String name) {
        super();
        this.ligado = false;
        this.operacao = "Auto";
        this.temperatura = 22;
        this.velocidade = 1;
        this.name = name;
    }
    
    public ArCondicionado(boolean ligado, int temperatura, int velocidade) {
        super();
        this.ligado = ligado;
        this.temperatura = temperatura;
        this.velocidade = velocidade;
        this.operacao = "Auto";
        this.name = "Ar Condicionado " + sequence++;
    }

    public ArCondicionado(String name, boolean ligado, int temperatura, int velocidade) {
        super();
        this.ligado = ligado;
        this.temperatura = temperatura;
        this.velocidade = velocidade;
        this.operacao = "Auto";
        this.name = name;
    }
    
    public void ligar() throws Exception {
        if (ligado == true) {
            throw new Exception("Ar ja esta ligado!");
        } else {
            ligado = true;
        }
    }
    
    public void desligar() throws Exception {
        if (ligado == false) {
            throw new Exception("Ar ja esta desligado!");
        } else {
            ligado = false;
        }
    }

    public void aumentarTemperatura() throws Exception {
        // Se resfriando pode chegar a 25 graus
        // Se aquecendo pode chegar a 30 graus
        if (!ligado) {
            throw new Exception("Ar condicionado desligado!");
        } else if (operacao.equals("Resfriar") && temperatura == 25) {
            throw new Exception("Resfriar pode chegar a 25 graus!");
        } else if ((operacao.equals("Aquecer") || operacao.equals("Auto")) && temperatura == 30) {
            throw new Exception("Auto ou Aquecer pode chegar a 30 graus!");
        } else if (operacao.equals("Ventilar")) {
            throw new Exception("Operação inválida para aumentar!");
        }
        temperatura++;
    }

    public void diminuirTemperatura() throws Exception {
        // Se resfriando pode chegar a 15 graus
        // Se aquecendo pode chegar a 20 graus
        if (!ligado) {
            throw new Exception("Ar condicionado desligado!");
        } else if (operacao.equals("Resfriar") && temperatura == 15) {
            throw new Exception("Resfriar pode chegar a 15 graus!");
        } else if ((operacao.equals("Aquecer") || operacao.equals("Auto")) && temperatura == 20) {
            throw new Exception("Auto ou Aquecer pode chegar a 20 graus!");
        } else if (operacao.equals("Ventilar")) {
            throw new Exception("Operação inválida para aumentar!");
        }
        temperatura--;
    }

    public void aumentarVelocidade() throws Exception {
        if (!ligado) {
            throw new Exception("Ar condicionado desligado!");
        } else if (velocidade == 3) {
            throw new Exception("Velocidade máxima atingida");
        }
        velocidade++;
    }

    public void diminuirVelocidade() throws Exception {
        if (!ligado) {
            throw new Exception("Ar condicionado desligado!");
        } else if (velocidade == 1) {
            throw new Exception("Velocidade mínima atingida");
        }
        velocidade--;
    }

    public void setOperacao(String op) throws Exception {
        if (!ligado) {
            throw new Exception("Ar condicionado desligado!");
        } else if (!(op.equals("Auto") || op.equals("Resfriar") || op.equals("Aquecer") || op.equals("Ventilar"))) {
            throw new Exception("Operação invalida!");
        }
        operacao = op;
        if (!operacao.equals("Resfriar") && temperatura < 20) {
            temperatura = 20;
        } else if (operacao.equals("Resfriar") && temperatura > 25) {
            temperatura = 25;
        }
    }
    
    public void setOperacao() {
        if (operacao.equals("Auto"))
           operacao = "Resfriar";
        else if (this.operacao.equals("Resfriar"))
           operacao = "Desumidificar"; 
        else if (this.operacao.equals("Desumidificar"))
           operacao = "Aquecer"; 
        else if (this.operacao.equals("Aquecer"))
           operacao = "Ventilar"; 
        else
           operacao = "Auto"; 
    }
    
    @Override
    public String toString() {
        return name + " | " + ligado + " | " + operacao + " | "+ temperatura + " | " + velocidade;
    }
}
