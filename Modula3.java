package aula02;

import javax.swing.JOptionPane;

class Modula3 {
	
	static double Hipotenusa(double cateto1, double cateto2) {
		return Math.sqrt(cateto1*cateto1 + cateto2*cateto2);		
	}
	
	

	public static void main(String[] args) {
		double cat1, cat2;
		String resposta;
		
		resposta = JOptionPane.showInputDialog("CATETO 1") ;
		cat1 = Double.parseDouble(resposta);
		
		resposta = JOptionPane.showInputDialog("CATETO 2");
		cat2 = Double.parseDouble(resposta);
		
		JOptionPane.showMessageDialog(null, "Hipotenusa "+Modula3.Hipotenusa(cat1, cat2));	
		

	}

}
