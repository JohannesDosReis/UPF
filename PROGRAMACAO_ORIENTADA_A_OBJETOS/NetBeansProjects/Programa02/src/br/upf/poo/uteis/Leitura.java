/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package br.upf.poo.uteis;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Scanner;

/**
 * Classe utilitária para usar em programas quando for necessário fazer
 * inputs pelo teclado em programas com front console.
 * @author Johannes Dos Reis
 */
public class Leitura {

    /**
     * Método para ler uma String qualquer.
     * Exemplo: nome, endereço etc.
     * @param msg É a String de mensagem que será apresentada ao usuário
     * para orientálo sobre o que deve digitar.
     * @return retorna a String liga do usuário.
     */
    public static String lerString(String msg){
        System.out.print(msg);
        return new Scanner(System.in).nextLine();
    }

    public static Boolean lerBollean(String msg){
        System.out.print(msg);
        return new Scanner(System.in).hasNextBoolean();
    }

    public static double lerDouble(String msg){
        System.out.print(msg);
        return new Scanner(System.in).nextDouble();
    }

    public static float lerFloat(String msg){
        System.out.print(msg);
        return new Scanner(System.in).nextFloat();
    }

    public static int lerInt(String msg){
        System.out.print(msg);
        return new Scanner(System.in).nextInt();
    }


    public static Date lerDate(String msg) {
        String dLida = lerString(msg);
        SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy");
        sdf.setLenient(false);
        try {
            return sdf.parse(dLida);
        } catch (ParseException e) {
            System.out.println("Data  inválida!");
            return lerDateTime(msg);
        }
    }

    public static Date lerDateTime(String msg){
        String dLida = lerString(msg);
        SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy HH:mm");
        sdf.setLenient(false); // desativa a correção
        try {
            return sdf.parse(dLida);
        } catch (ParseException e) {
            System.out.println("Data e hora inválidos!");
            return lerDateTime(msg);
        }
    }
}
