package aula02;

import javax.swing.JOptionPane;

class vetor {

	public static void main(String[] args) {
		int i;
		String[] nome;
		nome = new String[3];
		nome[0] = "Ana";
		nome[1] = "Bob";
		nome[2] = "Caio";
		
	for(i = 0;i<nome.length;i++) {
		JOptionPane.showMessageDialog(null, nome[i]);
	}
	
	
	}

}
