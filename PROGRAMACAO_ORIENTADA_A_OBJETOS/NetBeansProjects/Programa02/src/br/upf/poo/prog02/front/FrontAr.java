/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package br.upf.poo.prog02.front;

import br.upf.poo.prog02.dominio.ArCondicionado;
import br.upf.poo.uteis.Leitura;

import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.Date;

/**
 *
 * @author Johannes Dos Reis
 */
public class FrontAr {

    private static String opcao = "";
    private static ArrayList<ArCondicionado> arList = new ArrayList();
    private static ArCondicionado arSelecionado;

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        // testeLerDateHora();

        while (!opcao.equals("S")) {
            mostrarMenu();
            lerOpcao();
            executarOperacao();
            if (arSelecionado != null) {
                mostrarEstado();
            }
        }

    }

    private static void testeLerDateHora() {
        Date agenda = Leitura.lerDateTime("Informe data e hora da agenda: ");
        SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy HH:mm");
        System.out.println(sdf.format(agenda));
        Date hoje = new Date();
        System.out.println("A data do sistema é " + sdf.format(hoje));
        Calendar c = Calendar.getInstance();
        System.out.println("usando calendar: " + sdf.format(c.getTime()));
        c.add(Calendar.YEAR, 1);
        System.out.println("+ 1 ano: " + sdf.format(c));
        c.add(Calendar.MONDAY, -2);
        System.out.println("+ 1 ano - 2 meses: " + sdf.format(c));
    }

    private static void mostrarMenu() {
        System.out.println("------------------------");
        if (!arList.isEmpty()) {
            System.out.println(arSelecionado != null ? "Ar '" + arSelecionado.getName() + "' selecionado"
                    : "Nenhum ar selecionado");
        }
        System.out.println("AA - Adicionar Ar Condicionado");
        if (!arList.isEmpty()) {
            System.out.println("RA - Remover Ar Condicionado");
            System.out.println("EA - Escolher Ar Condicionado");
            if (arSelecionado == null) {
                System.out.println("Nenhum ar selecionado");
            } else {
                System.out.println("Ar Selecionado - " + arSelecionado.getName());
                if (arSelecionado.getEstado()) {
                    System.out.println("D - Desigar");
                    System.out.println("EO - Escolher operacao");
                    System.out.println("AT - Aumentar temperatura");
                    System.out.println("DT - Diminuir temperatura");
                    System.out.println("AV - Aumentar velocidade");
                    System.out.println("DV - Diminuir velocidade");

                } else {
                    System.out.println("L - Ligar");
                }
            }
        }
        // ...
        System.out.println("S - Sair");
    }

    private static void lerOpcao() {
        opcao = Leitura.lerString("Informe a opção: ");
    }

    private static void mostrarArList() {
        int lenght = arList.size();
        for (int i = 0; i < lenght; i++) {
            System.out.println("Ar " + i + " - " + arList.get(i).getName());
        }
    }

    private static void executarOperacao() {
        switch (opcao) {
        case "AA": {
            // String nm = Leitura.lerString("Digite um nome para o ar: ");;
            ArCondicionado novo = new ArCondicionado();
//            novo.inicializar();
            arList.add(novo);
        }
            break;
        case "RA": {
            mostrarArList();
            int i = Leitura.lerInt("Digite o numero do ar que deseja remover: ");
            arList.remove(i);
        }
            break;
        case "EA": {
            mostrarArList();
            int i = Leitura.lerInt("Digite o numero do ar que deseja escolher: ");
            try {
                arSelecionado = arList.get(i);
            } catch (Exception e) {
                System.out.println("Opção invalida");
            }
        }
            break;
        case "L": {
            // ligar um aparelho de ar
            if (arSelecionado != null) {
                arSelecionado.ligar();
            }
            break;
        }
        case "D": {
            // desligar o aparelho de ar
            if (arSelecionado != null) {
                arSelecionado.desligar();
            }
        }
            break;
        case "AT": {
            if (arSelecionado != null) {
                try {
                    arSelecionado.aumentarTemperatura();
                } catch (Exception e) {
                    System.out.println(e.getMessage());
                }
            }
        }
            break;
        case "DT": {
            if (arSelecionado != null) {
                try {
                    arSelecionado.diminuirTemperatura();
                } catch (Exception e) {
                    System.out.println(e.getMessage());
                }
            }
        }
            break;
        case "AV": {
            if (arSelecionado != null) {
                try {
                    arSelecionado.aumentarVelocidade();
                } catch (Exception e) {
                    System.out.println(e.getMessage());
                }
            }
        }
            break;
        case "DV": {
            if (arSelecionado != null) {
                try {
                    arSelecionado.diminuirVelocidade();
                } catch (Exception e) {
                    System.out.println(e.getMessage());
                }
            }

        }
        case "EO": {
            if (arSelecionado != null) {
                String op = Leitura.lerString("Digite a operacao desejada: ");
                try {
                    arSelecionado.setOperacao(op);
                } catch (Exception e) {
                    System.out.println(e.getMessage());
                }
            }
        }
        }
    }

    private static void mostrarEstado() {
        boolean state = arSelecionado.getEstado();
        System.out.println("------------------------");
        System.out.println("Estado: " + (state ? "Ligado" : "Desligado"));
        if (state) {
            System.out.println("Temperatura: " + arSelecionado.getTemperatura());
            System.out.println("Velocidade: " + arSelecionado.getVelocidade());
            System.out.println("Operacação: " + arSelecionado.getOperacao());
        }
    }
}
