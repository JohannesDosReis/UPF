package br.upf.poo02.dominio;

public class ArCondicionado {

    //Atributos
    private boolean ligado;
    private int temperatura;
    private int velocidade;
    private String operacao;

    public ArCondicionado() {
        this.ligado = false;
        this.temperatura = 22;
        this.velocidade = 1;
        operacao = "Auto";
    }

    public ArCondicionado(boolean ligado, int temperatura, int velocidade) {
        super();
        this.ligado = ligado;
        this.temperatura = temperatura;
        this.velocidade = velocidade;
        operacao = "Auto";
    }

    public String getOperacao() {
        return operacao;
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
    
    public boolean isLigado() {
        return ligado;
    }

    public int getTemperatura() {
        return temperatura;
    }

    public int getVelocidade() {
        return velocidade;
    }

    public void desligar() throws Exception {
        if (ligado == false) {
            throw new Exception("Ar ja esta desligado!");
        } else {
            ligado = false;
        }
    }

    public void diminuirVelocidade() throws Exception {
        if (velocidade == 1) {
            throw new Exception("Velocidade Minima, impossivel diminuir!");
        } else {
            velocidade--;
        }
    }

    public void aumentarVelocidade() throws Exception {
        if (velocidade == 3) {
            throw new Exception("Velocidade Maxima, impossivel aumentar!");
        } else {
            velocidade++;
        }
    }

    public void diminuirTemperatura() throws Exception {
        if (temperatura == 18) {
            throw new Exception("Temperatura Minima, impossivel diminuir!");
        } else {
            temperatura--;
        }
    }

    public void aumentarTemperatura() throws Exception {
        if (temperatura == 32) {
            throw new Exception("Temperatura Maxima, impossivel aumentar!");
        } else {
            temperatura++;
        }
    }

    public void ligar() throws Exception {
        if (ligado == true) {
            throw new Exception("Ar ja esta ligado!");
        } else {
            ligado = true;
        }
    }

    @Override
    public String toString() {
        return ligado+" | "+operacao+" | "+temperatura+" | "+velocidade;
    }
        
}
