/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package br.upf.poo.ar.front;

import br.upf.poo.prog02.dominio.ArCondicionado;
import java.util.ArrayList;
import java.util.List;
import javax.faces.application.FacesMessage;
import javax.faces.bean.ManagedBean;
//import javax.faces.bean.RequestScoped;
import javax.faces.bean.SessionScoped;
import javax.faces.context.FacesContext;
//import javax.faces.bean.ViewScoped;

/**
 *
 * @author Johannes Dos Reis
 */

@ManagedBean // a classe gerencia as instancias o frontAr é a instancia criada por ele
//@RequestScoped
@SessionScoped // os objetos ficam no escopo
//@ViewScoped
public class FrontAr {
    private List<ArCondicionado> lista;
    private ArCondicionado arSelecionado;
    
    public ArCondicionado getArSelecionado() {
        return arSelecionado;
    }


    public FrontAr() {
//        this.lista = new ArrayList<ArCondicionado>();
//        this.lista = new ArrayList<>();
        this.lista = new ArrayList();
    }

    public List<ArCondicionado> getLista() {
        return lista;
    }
    
    public void criarAparelho() {
        this.lista.add(new ArCondicionado());
    }
    
    public void selecionar(Integer index) {
        this.arSelecionado = lista.get(index);
    }
    
    public void operacao(String oper){
        try {
            switch (oper) {
                case "ligar": {
                    arSelecionado.ligar();
                }
                break;
                 case "desligar": {
                    arSelecionado.desligar();
                }
                break;
                 case "+ temp": {
                    arSelecionado.aumentarTemperatura();
                }
                break;
                 case "- temp": {
                    arSelecionado.diminuirTemperatura();
                }
                break; 
                case "+ vel": {
                    arSelecionado.aumentarVelocidade();
                }
                break; 
                case "- vel": {
                    arSelecionado.diminuirVelocidade();
                }
                break; 
                case "oper": {
                    arSelecionado.setOperacao();
                }
                break;
                
                
            }
        } catch (Exception exception) {
            // Adiconar mensagem na view
            FacesContext.getCurrentInstance().addMessage(null, new FacesMessage(exception.getMessage()));
        }
    }
    
}
