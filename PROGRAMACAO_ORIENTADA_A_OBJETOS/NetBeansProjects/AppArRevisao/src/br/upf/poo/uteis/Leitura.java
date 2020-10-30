package br.upf.poo.uteis;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Scanner;

/*
 * Classe utilitaria para usar em programas quando for necessario fazer
 * inputs pelo teclado em programas com front console.
 * @author PG
 */

public class Leitura {

	/*Metodo para ler um String qualquer.
	 * @param msg a String de mensagem que sera apresentada ao usuario
	 * para orientalo sobre o que de digitar.
	 * @return retorna a String liga do usuario.
	 */
	
	public static String lerString(String msg) {
		System.out.print(msg);
		return new Scanner(System.in).nextLine();
	}
	
	public static char lerChar(String msg) {
		System.out.print(msg);
		return new Scanner(System.in).next().charAt(0);
	}

	public static int lerInt(String msg) {
		System.out.print(msg);
		return new Scanner(System.in).nextInt();
	}
	
	public static Date lerDateTime(String msg) {
		String dLida = lerString(msg);
		SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy HH:mm");
		sdf.setLenient(false); //Desligar correcao de data e hora
		try {
			return sdf.parse(dLida);
		} catch (ParseException e) {
			System.out.println("Data e Hora Invalidos");
			return lerDateTime(msg);
		} 
	}
}
