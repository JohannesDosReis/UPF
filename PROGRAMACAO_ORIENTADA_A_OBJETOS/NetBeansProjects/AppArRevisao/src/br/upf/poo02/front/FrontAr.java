package br.upf.poo02.front;

import java.util.ArrayList;

import br.upf.poo.uteis.Leitura;
import br.upf.poo02.dominio.ArCondicionado;

public class FrontAr {

	private static String opcao;
	private static ArrayList<ArCondicionado> listAr = new ArrayList<ArCondicionado>();
	private static ArCondicionado ar = new ArCondicionado();

	public static void main(String[] args) {

		System.out.println("= Ar System =============");
		System.out.println("=========================");
		cadastrarAr();
	}
	
	private static void cadastrarAr() {

		if(listAr.isEmpty()) {
			
			Character op = Leitura.lerChar("Voce nao possui nem um ar cadastrado!\nGostaria de cadastra-lo? ");
			if(op.toString().toUpperCase().charAt(0) == 'Y') {
				listAr.add(ar);
				System.out.println("Ar criado!\n");
				executarOperacao(ar);
			}else {
				System.out.println("\nNenhum Ar cadastrado, o programa sera encerrado!\n");
				System.exit(0);
			}
		}else {

			System.out.println("=========================\n");
			System.out.println("Voce ja possui esses apararelhos de Ar cadastrados:\n");
			int n = listAr.size();
			for (int i=0; i<n; i++) {
				System.out.printf(" [%d] %s\n", i, listAr.get(i) );
			}

			System.out.println("\n=========================");
			char op = Leitura.lerChar(" [N] Cadastrar Novo\n [U] Usar um existente\n [E] Encerrar\n\n => ");
			System.out.println("=========================\n");
			if(op == 'N') {
				ar = new ArCondicionado(false, 22, 1);
				listAr.add(ar);
				System.out.println("Ar criado!\n");
				executarOperacao(ar);
			}else if(op == 'U'){
				int opAr = Leitura.lerInt("Escolha o numero do Ar a ser usado: ");
				System.out.print("\n");
				executarOperacao(listAr.get(opAr));
			}else {
				System.exit(0);
			}
		}
	}

	private static void executarOperacao(ArCondicionado ind) {

		do {
			mostrarMenu();
			lerOpcao();
			switch (opcao.toUpperCase()) {
			case "L":
				//Ligar um aparelho de ar
				try {
					ind.ligar();
				}catch (Exception e) {
					System.out.println(e.getMessage());
				}
				break;
			case "D":
				//Desligar
				try {
					ind.desligar();
				}catch (Exception e) {
					System.out.println(e.getMessage());
				}
				break;
			case "AV":
				try {
					ind.aumentarVelocidade();
				} catch (Exception e) {
					System.out.println(e.getMessage());
				}
				break;
			case "DV":
				try {
					ind.diminuirVelocidade();
				} catch (Exception e) {
					System.out.println(e.getMessage());
				}
				break;
			case "AT":
				try {
					ind.aumentarTemperatura();
				} catch (Exception e) {
					System.out.println(e.getMessage());
				}
				break;
			case "DT":
				try {
					ind.diminuirTemperatura();
				} catch (Exception e) {
					System.out.println(e.getMessage());
				}
				break;
			case "EA":
				mostrarEstadoAr();
				break;
                        case "OP":
				ar.setOperacao();
				break;                                
			default:
				System.out.println("Opcao Invalida!\n");
				break;
			}
		}while(!opcao.equalsIgnoreCase("D"));
		cadastrarAr();
	}

	private static void lerOpcao() {

		opcao = Leitura.lerString("\nInforme a Opcao: ");
	}

	private static void mostrarMenu() {
		System.out.println("=========================");
		if(ar.isLigado() == false) {
			System.out.println("L - Ligar");
			System.out.println("=========================");
		}else {
			System.out.println("D - Desligar");
			if(ar.getVelocidade() < 3) {
				System.out.println("AV - Aumentar Velocidade");
			}
			if(ar.getVelocidade() > 1) {
				System.out.println("DV - Diminuir Velocidade");
			}
			if(ar.getTemperatura() < 32) {
				System.out.println("AT - Aumentar Temperatura");
			}
			if(ar.getTemperatura() > 18) {
				System.out.println("DT - Diminuir Temperatura");
			}
			System.out.println("OP - Muda Operação");
			System.out.println("EA - Mostrar Estado do Ar");
			System.out.println("=========================");
		}
	}

	public static void mostrarEstadoAr() {
		System.out.println("\n= Status do Ar ==========");
		System.out.println("=========================");
		if(ar.isLigado() == true) {
			System.out.println("Estado: Ligado");
			System.out.println("Temperatura: "+ar.getTemperatura());
			System.out.println("Velocidade: "+ar.getVelocidade());
                        System.out.println("Operação: "+ar.getOperacao());
		}else {
			System.out.println("Estado: Desligado");
		}
		System.out.println("=========================\n");
	}
}
