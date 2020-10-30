/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package br.upf.poo.imc.front;

import java.util.List;

import br.upf.poo.imc.dominio.Imc;
import java.util.ArrayList;
import javax.faces.bean.ManagedBean;
import javax.faces.bean.SessionScoped;



/**
 *
 * @author Johannes Dos Reis
 */
@ManagedBean
@SessionScoped
public class FrontImc {
    private List<Imc> lista;
    private Imc imcSelecionado;
    private String nomeNovo;
    private float alturaNovo;
    private float pesoNovo;

    public String getNomeNovo() {
        return nomeNovo;
    }

    public void setNomeNovo(String nomeNovo) {
        this.nomeNovo = nomeNovo;
    }

    public float getAlturaNovo() {
        return alturaNovo;
    }

    public void setAlturaNovo(float alturaNovo) {
        this.alturaNovo = alturaNovo;
    }

    public float getPesoNovo() {
        return pesoNovo;
    }

    public void setPesoNovo(float pesoNovo) {
        this.pesoNovo = pesoNovo;
    }
    
     public FrontImc() {
        this.lista = new ArrayList();
    }

    public List<Imc> getLista() {
        return lista;
    }

    public Imc getImcSelecionado() {
        return imcSelecionado;
    }
    



    public void criarImc() {
        this.imcSelecionado = new Imc(this.nomeNovo, this.alturaNovo, this.pesoNovo);
        this.lista.add(imcSelecionado);
    }

}
