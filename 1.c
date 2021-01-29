Arteria* a;       // ponteiro para artéria
double f;         // frequência
bool   viscoso;   // se é viscoso ou não
double m_v;       // multiplicador viscoso
double phi0;      // phi_0
double p0;        // pressão de entrada

bool fase_um(Arteria* a, double f, bool viscoso
                , double v_m,double phi0){
    
    if(!a->folha){ //SE o segmento não for "folha"
        if(a->esquerda)//SE o segmento possuir ramificação à esquerda
            fase_um(a->esquerda,f,v_m,phi0);
        if(a->direita)//SE o segmento possuir ramificação à direita
            fase_um(a->direita,f,v_m,phi0);
    }

    calcula_velocidade_de_onda();
    calcula_velocidade_angular();
    calcula_beta()

    if(!viscous){
        calcula_admitancia();
    } else {
        calcula_alpha();
        calcula_fator_viscoso();
        calcula_modulo_de_young_viscoso();
        calcula_velocidade_de_onda_viscosa();
        calcula_beta_viscoso();
        calcula_admitancia_viscosa();
    }

    if(a->folha){
        a->R = 0;  //Coeficiente de Reflexão é ZERO
        a->Ye = Y; //Admitância Efetiva é igual Admitância (Ye = Y)
    } else {
        calcula_coeficiente_de_reflexao();
        calcula_admitancia_efetiva();
    }
}

bool fase_dois(Arteria* a, double p0, complex<double> admitancia_raiz){
    if(a->raiz){//SE o segmento for raiz
        a->_p = p0; //Pressão média = pressão de entrada
    } else {
        calcula_pressao_media();
    }

    calcula_onda_pressao();
    calcula_onda_fluxo();

    if(!a->folha){ //SE o segmento não for "folha"
        if(a->esquerda)//SE o segmento possuir ramificação à esquerda
            fase_um(a->esquerda,f,v_m,phi0);
        if(a->direita)//SE o segmento possuir ramificação à direita
            fase_um(a->direita,f,v_m,phi0);
    }
}