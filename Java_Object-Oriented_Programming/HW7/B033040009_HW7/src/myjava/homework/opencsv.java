package myjava.homework;
import com.opencsv.CSVReader;
import java.util.HashMap;
import java.io.FileReader;
import java.io.IOException;
import java.text.DecimalFormat;

import org.jfree.chart.ChartFactory;
import org.jfree.chart.ChartPanel;
import org.jfree.chart.JFreeChart;
import org.jfree.data.category.CategoryDataset;
import org.jfree.data.category.DefaultCategoryDataset;
import org.jfree.ui.ApplicationFrame;
import org.jfree.util.TableOrder;

public class opencsv extends ApplicationFrame {
	private static final long serialVersionUID = 1L;

	public opencsv(final String title, HashMap<String, Integer> product_count, HashMap<String, Integer> sex_count) {
        super(title);
        final CategoryDataset dataset = createDataset(product_count, sex_count);
        final JFreeChart chart = createChart(dataset);
        final ChartPanel chartPanel = new ChartPanel(chart);
        chartPanel.setPreferredSize(new java.awt.Dimension(600, 380));
        setContentPane(chartPanel);
    }
    
    private CategoryDataset createDataset(HashMap<String, Integer> product_count, HashMap<String, Integer> sex_count) {
        
        DefaultCategoryDataset dataset = new DefaultCategoryDataset();
        double total = product_count.get("Product_A") + product_count.get("Product_B") + product_count.get("Product_C");
        
        DecimalFormat df = new DecimalFormat("#.0"); 
        double product_A_percentage = product_count.get("Product_A") / total * 100;
        double product_B_percentage = product_count.get("Product_B") / total * 100;
        double product_C_percentage = product_count.get("Product_C") / total * 100;
        product_A_percentage = Double.parseDouble(df.format(product_A_percentage));
        product_B_percentage = Double.parseDouble(df.format(product_B_percentage));
        product_C_percentage = Double.parseDouble(df.format(product_C_percentage));
        String series_product_A = "Product A : " + product_A_percentage + "%";
        String series_product_B = "Product B : " + product_B_percentage + "%";
        String series_product_C = "Product C : " + product_C_percentage + "%";
        dataset.addValue(product_count.get("Product_A") , "Product_type", series_product_A);
        dataset.addValue(product_count.get("Product_B") , "Product_type", series_product_B);
        dataset.addValue(product_count.get("Product_C") , "Product_type", series_product_C);
        
        double male_percentage = sex_count.get("M") / total * 100;
        double female_percentage = sex_count.get("F") / total * 100;
        male_percentage = Double.parseDouble(df.format(male_percentage));
        female_percentage = Double.parseDouble(df.format(female_percentage));
        String series_male = "Male : " + male_percentage + "%";
        String series_female = "Female : " + female_percentage + "%";
        dataset.addValue(sex_count.get("M"), "id_sex", series_male);
        dataset.addValue(sex_count.get("F"), "id_sex", series_female);
        
        return dataset; 
    }
    
    private JFreeChart createChart(final CategoryDataset dataset) {
        final JFreeChart chart = ChartFactory.createMultiplePieChart(
            "",  // chart title
            dataset,               // dataset
            TableOrder.BY_ROW,
            false,                  // include legend
            true,
            false
        );
        return chart;
    }
	
	public static void main(String[] args) throws IOException{
		   CSVReader reader = new CSVReader(new FileReader("query_result.csv"));
		   HashMap<String, Integer> product_count = new HashMap<String, Integer>();
		   HashMap<String, Integer> sex_count = new HashMap<String, Integer>();
		     String [] nextLine;
		     nextLine = reader.readNext(); // header
		     while ((nextLine = reader.readNext()) != null) {
		    	if(product_count.get(nextLine[1]) == null)  {
		    		product_count.put( nextLine[1], 1);
		    	}
		    	else {
		    		product_count.put( nextLine[1], (int) product_count.get(nextLine[1]) + 1 );
		    	}
		    	
		    	if(sex_count.get(nextLine[2]) == null) {
		    		sex_count.put(nextLine[2], 1);
		    	}
		    	else {
		    		sex_count.put(nextLine[2], (int) sex_count.get(nextLine[2]) + 1);
		    	}
		     }
		   opencsv product_type = new opencsv( "JAVA_HW7" , product_count, sex_count);  
		   product_type.setSize( 1120 , 734 );    
		   product_type.setVisible( true );  
		   reader.close();
	}
}
