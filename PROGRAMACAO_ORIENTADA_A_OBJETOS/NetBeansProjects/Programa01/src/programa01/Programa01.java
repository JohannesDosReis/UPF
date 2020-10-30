/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package programa01;

/**
 *
 * @author Johannes Dos Reis
 */
public class Programa01 {
    
//    Atributos
    private static boolean ligado;
    private static int temperatura;
    private static int velocidade;
    private static String operacao;

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        inicializar();
        ligar();
        try {
            aumentarTemperatura();
            aumentarTemperatura();
            aumentarTemperatura();
            aumentarTemperatura();
            aumentarTemperatura();
            aumentarTemperatura();
            aumentarTemperatura();
            aumentarTemperatura();
            aumentarTemperatura();
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }

    private static void inicializar() {
        ligado = false;
        operacao = "Auto";
        temperatura = 22;
        velocidade = 1;
    }

    private static void ligar() {
         ligado = true;
    }

    private static void aumentarTemperatura() throws Exception {
        // Se resfriando pode chegar a 25 graus
        // Se aquecendo pode chegar a 30 graus
        if (operacao.equals("Resfriando") && temperatura == 25){
            throw new Exception("Resfriando pode chegar a 25 graus!");
        } else if (
                (operacao.equals("Aquecendo") || operacao.equals("Auto"))
                        && temperatura == 30){
            throw new Exception("Auto ou Aquecendo pode chegar a 30 graus!");
        } else if (operacao.equals("Ventilando")){
            throw new Exception("operação inválida para aumentar!");
        }
        temperatura ++;
    }
    
    private static void diminuirTemperatura(){
        temperatura--;
    }
    
}