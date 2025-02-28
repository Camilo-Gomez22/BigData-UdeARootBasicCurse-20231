// Read the previously produced N-Tuple and print on screen its content

void Example5_read_ntuple_from_file(){

  // Open a file, save the ntuple and close the file
  TFile in_file("conductivity_experiment.root");
  TNtuple* my_tuple;
  in_file.GetObject("cond_data",my_tuple);
  float pot,cur,temp,pres;
  float* row_content;
  
  cout << "Potential\tCurrent\tTemperature\tPressure\n";
 
  for (int irow=0;irow<my_tuple->GetEntries();++irow){
    my_tuple->GetEntry(irow);
    row_content = my_tuple->GetArgs();
    pot = row_content[0];
    cur = row_content[1];
    temp = row_content[2];
    pres = row_content[3];
    cout << pot << "\t" << cur << "\t" << temp
	 << "\t" << pres << endl;
  }
  
}
//its branches are assigned to variables and GetEntry(irow) automatically fills them with the content for a specific row.
//By doing so, the logic for reading the n-tuple and the code to process it can be split and the source code remains clear.
  
