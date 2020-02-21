package Aplicativo;

import javax.swing.JOptionPane;

class Aplicativo
{
    static void leitura(double[] temp)
    {
        int i;
        String resposta;
        
        for(i = 0; i < temp.length; i++)
        {
            resposta = JOptionPane.showInputDialog(
                    "Digite uma temperatura");
            temp[i] = Double.parseDouble(resposta);
        }
    }
    
    static double menor(double[] temp)
    {
        double min;
        int i;
        
        min = temp[0];
        for(i = 1; i < temp.length; i++)
            if(temp[i] < min)
                min = temp[i];
        return min;
    }
    
    static double maior(double[] temp) {
    	double max=0;
    	int i;
    	for(i = 1; i < temp.length; i++) {
    		if(temp[i] > max)
    			max = temp[i];
    		
    	}
    	return max;
    }
    
    static double media(double[] temp) {
    	int i;
    	double med = 0;
    	for(i=0;i<temp.length ;i++) {
    		med += temp[i];
    	}
    	return med / i;
    	
    }
    
    
    static void imprimir(double[] temp) {
    	 int i;
    	 for(i=0;i<temp.length;i++)
    		 JOptionPane.showMessageDialog(null, "temperatura "+ (i+1)+ " : "+temp[i]);
    	
    	
    }
    
    
    
    public static void main(String[] args)
    {
        String opcao;
        double[] temperatura;
        
        temperatura = new double[3];
        for(;;)
        {
            opcao = JOptionPane.showInputDialog(
                    "1 - Leitura das temperaturas\n" +
                    "2 - Calculo da menor temperatura\n" +
                    "3 - Maior temperatura\n" +
                    "4 - Imprimir temperaturas\n" +
                    "5 - Terminar Programa\n"+
                    "6 - Media");
            
            		
            if(opcao == null || opcao.equals("5"))
                break;
            else if(opcao.equals("1"))
                    Aplicativo.leitura(temperatura);
                else if(opcao.equals("2"))
                        JOptionPane.showMessageDialog(null,"Menor temperatura: " + Aplicativo.menor(temperatura));
                else if(opcao.equals("3"))
                	JOptionPane.showMessageDialog(null, Aplicativo.maior(temperatura));
                else if(opcao.equals("4"))
                	Aplicativo.imprimir(temperatura);
                else if(opcao.equals("6"))
                	JOptionPane.showMessageDialog(null, Aplicativo.media(temperatura));
        }
    }
}
