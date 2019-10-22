void GC_reverse()
{
  Serial.println("Reversed GCs");
  for(int i = 0; i < 8; i++)
  {
    Serial.print("GC ");
    Serial.print(i);
    Serial.print(": ");
    for(int j = 0; j < 31; j++)
    {
      if(GC_result[i][j] == 0) // if bit == 0, change to 1
      {
        GC_result[i][j] = 1;
      }
      else // if bit == 1, change to 0
      {
        GC_result[i][j] = 0;
      }
    Serial.print(GC_result[i][j]);
    }
    Serial.println();
  }
}
