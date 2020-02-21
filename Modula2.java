package aula02;

import javax.swing.JOptionPane;

class Modula2 {
	
	static void massa(float peso, float altura) {
		float imc = peso/(altura*altura);
		if(imc <20)
			JOptionPane.showMessageDialog(null, "abaixo do peso");
		else if(imc >=20 && imc <=25)
			JOptionPane.showMessageDialog(null, "peso normal");
		else
			JOptionPane.showMessageDialog(null, "acima do peso");
	
	}


public static void main(String[] args) {
	float pes, alt;
	String resposta;
	
	resposta = JOptionPane.showInputDialog("PESO") ;
	pes = Float.parseFloat(resposta);
	
	resposta = JOptionPane.showInputDialog("ALTURA") ;
	alt = Float.parseFloat(resposta);
	
	Modula2.massa(pes, alt);

	}
	
}
	
	
	
	
