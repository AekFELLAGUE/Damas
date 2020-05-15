#include<iostream>
using namespace std;
void player_2(char mat[6][8]){
	int pos_l,pos_c;
	char dest,destiny;
	bool rep;
	do{
		rep=1;
		cout<<"\n\n\t\t\t    <<< Player 2 >>>\n\n\t\t\tchoose the coordinates\n";
		do
		{
		cout<<"\n  Vertically, from 1--->6: ";
		cin>>pos_l;
		if(cin.fail()) {
			cin.clear();
			cin.ignore();
			cout << "\nEnter a number" << endl;
		}
		}while((pos_l>6)||(pos_l<1));
		do
		{
		cout<<"\n  Horizontally, from 1--->8: ";
		cin>>pos_c;
		}while((pos_c>8)||(pos_c<1));
		for(int i=0;i<6;i++)
		{
			for(int j=0;j<8;j++)
			{
				if((i==pos_l-1)&&(j==pos_c-1))
				{
					if((mat[i][j]!='O')&&(mat[i][j]!='R'))
					{
						if((mat[i][j]=='X')||(mat[i][j]=='K'))
						{
							cout<<"Not yours";
							rep=0;
						}
						else if(mat[i][j]==' ')
							{
								cout<<"it's Empty!!!";
								rep=0;
								break;
							}
					}
					else if (mat[i][j]=='R')//the king
					{
						cout<<"\n\t\t\tYou are using the King";
						do
						{
							cout<<"\nAdvancing --A-- or going Back --B-- : ";
							cin>>destiny;
						}while((destiny!='A')&&(destiny!='a')&&(destiny!='B')&&(destiny!='b'));
						if ((destiny=='A')||(destiny=='a'))////advancing
						{
							do
							{
								cout<<"Left --L-- or Right --R-- : ";
								cin>>dest;
							}while((dest!='L')&&(dest!='l')&&(dest!='R')&&(dest!='r'));
							if((dest=='L')||(dest=='l'))////going left
							{
								if((j==0)||(i==0))
								{
									cout<<"Can't move this (limit)";
									rep=0;
								}
								else
								{
									if(mat[i-1][j-1]!=' ')
									{
										if((mat[i-1][j-1]=='R')||(mat[i-1][j-1]=='O'))
										{
											cout<<"Can't eat this (friend)";
											rep=0;
										}
										else
										{
											if((mat[i-2][j-2]==' '))
											{
												mat[i-2][j-2]='R';
												mat[i-1][j-1]=' ';
												mat[i][j]=' ';
												if(((j-4>=0)&&(i-4>=0))&&((mat[i-3][j-3]=='K')||(mat[i-3][j-3]=='X'))&&(mat[i-4][j-4]==' '))//double eat straight
												{
													mat[i-3][j-3]=' ';
													mat[i-4][j-4]='R';
													mat[i-2][j-2]=' ';
												}
												else if((i-4>=0)&&((mat[i-3][j-1]=='K')||(mat[i-3][j-1]=='X'))&&(mat[i-4][j]==' '))//dbl eat n straight
													{
														mat[i-4][j]='R';
														mat[i-3][j-1]=' ';
														mat[i-2][j-2]=' ';
													}
													else if((j-4>=0)&&((mat[i-1][j-3]=='K')||(mat[i-1][j-3]=='X'))&&(mat[i][j-4]==' '))//eat up down
														{
															mat[i-1][j-3]=' ';
															mat[i][j-4]='R';
															mat[i-2][j-2]=' ';
														}
											}
											else
											{
												cout<<"Can't eat this (face a block)";
												rep=0;
											}
										}
									}
									else
									{
										mat[i-1][j-1]='R';
										mat[i][j]=' ';
									}
								}//else of right
							}
							else
							{
								if((j==7)||(i==0))
								{
									cout<<"Can't move this (limit)";
									rep=0;
								}
								else
								{
									if(mat[i-1][j+1]!=' ')
									{
										if((mat[i-1][j+1]=='R')||(mat[i-1][j+1]=='O'))
										{
											cout<<"Can't eat this (friend)";
											rep=0;
										}
										else
										{
											if((mat[i-2][j+2]==' '))
											{
												mat[i-2][j+2]='R';
												mat[i-1][j+1]=' ';
												mat[i][j]=' ';
												if(((j+4<=7)&&(i-4>=0))&&((mat[i-3][j+3]=='K')||(mat[i-3][j+3]=='X'))&&(mat[i-4][j+4]==' '))//double eat straight
												{
													mat[i-3][j+3]=' ';
													mat[i-4][j+4]='R';
													mat[i-2][j+2]=' ';
												}
												else if((i-4>=0)&&((mat[i-3][j+1]=='K')||(mat[i-3][j+1]=='X'))&&(mat[i-4][j]==' '))//dbl eat n straight
													{
														mat[i-4][j]='R';
														mat[i-3][j+1]=' ';
														mat[i-2][j+2]=' ';
													}
													else if((j+4<=7)&&((mat[i-1][j+3]=='K')||(mat[i-1][j+3]=='X'))&&(mat[i][j+4]==' '))//eat up down
														{
															mat[i-1][j+3]=' ';
															mat[i][j+4]='R';
															mat[i-2][j+2]=' ';
														}
											}
											else
											{
												cout<<"Can't eat this (face a block)";
												rep=0;
											}
										}
									}
									else
									{
										mat[i-1][j+1]='R';
										mat[i][j]=' ';
									}
								}
							}
						}//else of back
						else
						{
							do
							{
								cout<<"Left --L-- or Right --R-- : ";
								cin>>dest;
							}while((dest!='L')&&(dest!='l')&&(dest!='R')&&(dest!='r'));
							if((dest=='L')||(dest=='l'))////back left
							{
								if((j==0)||(i==5))
								{
									cout<<"Can't move this (limit)";
									rep=0;
								}
								else
								{
									if(mat[i+1][j-1]!=' ')
									{
										if((mat[i+1][j-1]=='R')||(mat[i+1][j-1]=='O'))
										{
											cout<<"Can't eat this (friend)";
											rep=0;
										}
										else
										{
											if((mat[i+2][j-2]==' '))
											{
												mat[i+2][j-2]='R';
												mat[i+1][j-1]=' ';
												mat[i][j]=' ';
												if(((j-4>=0)&&(i+4<=5))&&((mat[i+3][j-3]=='K')||(mat[i+3][j-3]=='X'))&&(mat[i+4][j-4]==' '))//double eat straight
												{
													mat[i+3][j-3]=' ';
													mat[i+4][j-4]='R';
													mat[i+2][j-2]=' ';
												}
												else if((i+4<=5)&&((mat[i+3][j-1]=='K')||(mat[i+3][j-1]=='X'))&&(mat[i+4][j]==' '))//dbl eat n straight
													{
														mat[i+4][j]='R';
														mat[i+3][j-1]=' ';
														mat[i+2][j-2]=' ';
													}
													else if((j-4>=0)&&((mat[i+1][j-3]=='K')||(mat[i+1][j-3]=='X'))&&(mat[i][j-4]==' '))//eat up down
														{
															mat[i+1][j-3]=' ';
															mat[i][j-4]='R';
															mat[i+2][j-2]=' ';
														}
											}
											else
											{
												cout<<"Can't eat this (face a block)";
												rep=0;
											}
										}
									}
									else
									{
										mat[i+1][j-1]='R';
										mat[i][j]=' ';
									}
								}
							}//else of back right
							else
							{
								if((j==7)||(i==5))
								{
									cout<<"Can't move this (limit)";
									rep=0;
								}
								else
								{
									if(mat[i+1][j+1]!=' ')
									{
										if((mat[i+1][j+1]=='R')||(mat[i+1][j+1]=='O'))
										{
											cout<<"Can't eat this (friend)";
											rep=0;
										}
										else
										{
											if((mat[i+2][j+2]==' '))
											{
												mat[i+2][j+2]='R';
												mat[i+1][j+1]=' ';
												mat[i][j]=' ';
												if(((j+4<=7)&&(i+4<=5))&&((mat[i+3][j+3]=='K')||(mat[i+3][j+3]=='X'))&&(mat[i+4][j+4]==' '))//double eat straight
												{
													mat[i+3][j+3]=' ';
													mat[i+4][j+4]='R';
													mat[i+2][j+2]=' ';
												}
												else if((i+4<=5)&&((mat[i+3][j+1]=='K')||(mat[i+3][j+1]=='X'))&&(mat[i+4][j]==' '))//dbl eat n straight
													{
														mat[i+4][j]='R';
														mat[i+3][j+1]=' ';
														mat[i+2][j+2]=' ';
													}
													else if((j+4<=7)&&((mat[i+1][j+3]=='K')||(mat[i+1][j+3]=='X'))&&(mat[i][j+4]==' '))//eat up down
														{
															mat[i+1][j+3]=' ';
															mat[i][j+4]='R';
															mat[i+2][j+2]=' ';
														}
											}
											else
											{
												cout<<"Can't eat this (face a block)";
												rep=0;
											}
										}
									}
									else
									{
										mat[i+1][j+1]='R';
										mat[i][j]=' ';
									}
								}
							}
						}
					}//end of the king
					else
					{
						do
						{
							cout<<"\nLeft --L-- or Right --R--: ";
							cin>>dest;
						}while((dest!='L')&&(dest!='R')&&(dest!='r')&&(dest!='l'));
						if((dest=='l')||(dest=='L'))
						{
							if((j==0)||(i==0))
							{
								cout<<"Can't move this (limit)";
								rep=0;
							}
							else if (mat[i-1][j-1]!=' ')
									{
										if((mat[i-1][j-1]=='X')||(mat[i-1][j-1]=='K'))
										{
											if ((j-2>=0)&&(i-2>=0))
											{
												if(mat[i-2][j-2]==' ')
												{
													mat[i-2][j-2]='O';
													mat[i][j]=' ';
													mat[i-1][j-1]=' ';//we can't eat a member of our team
													if ((j-4>=0)&&(i-4>=0))
													{
														if(((mat[i-3][j-3]=='X')||(mat[i-3][j-3]=='K'))&&(mat[i-4][j-4]==' '))
														{
															mat[i-2][j-2]=' ';
															mat[i-4][j-4]='O';
															mat[i-3][j-3]=' ';
														}
														else if(((mat[i-3][j-1]=='X')||(mat[i-3][j-1]=='K'))&&(mat[i-4][j]==' '))
																{
																	mat[i-2][j-2]=' ';
																	mat[i-4][j]='O';
																	mat[i-3][j-1]=' ';
																}
													}
													else
													{
														if(i-4<=5)
														{
															if(((mat[i-3][j-1]=='X')||(mat[i-3][j-1]=='K'))&&(mat[i-4][j]==' '))
																{
																	mat[i-2][j-2]=' ';
																	mat[i-4][j]='O';
																	mat[i-3][j-1]=' ';
																}
														}
													}
												}
												else
												{
													cout<<"can't play this (face o x)";
													rep=0;
												}
											}
											else
											{
												cout<<"Can't move this(out the square)";
												rep=0;
											}
										}
										else
										{
											cout<<"Can't eat this (friend)";
											rep=0;
										}
									}
									else if (mat[i-1][j-1]==' ')
											{
												mat[i-1][j-1]=mat[i][j];
												mat[i][j]=' ';
											}
						}//else of right
						else
						{
										if((j==7)||(i==0))
										{
											cout<<"Can't move this (limit)";
											rep=0;
										}
										else if (mat[i-1][j+1]!=' ')
												{
													if((mat[i-1][j+1]=='X')||(mat[i-1][j+1]=='K'))
													{
														if ((j+2>=0)&&(i-2<=5))
														{
															if(mat[i-2][j+2]==' ')
															{
																mat[i-2][j+2]='O';
																mat[i][j]=' ';
																mat[i-1][j+1]=' ';//WE CAN't eat a member of team
																if ((j+4<=7)&&(i-4>=0))
																{
																	if(((mat[i-3][j+3]=='X')||(mat[i-3][j+3]=='K'))&&(mat[i-4][j+4]==' '))//double eat straight
																	{
																		mat[i-2][j+2]=' ';
																		mat[i-4][j+4]='O';
																		mat[i-3][j+3]=' ';
																	}
																	else if(((mat[i-3][j+1]=='X')||(mat[i-3][j+1]=='K'))&&(mat[i-4][j]==' '))//double eat not straight
																			{
																				mat[i-2][j+2]=' ';
																				mat[i-4][j]='O';
																				mat[i-3][j+1]=' ';
																			}
																}
																else
																{
																	if(i-4<=5)
																	{
																		if(((mat[i-3][j+1]=='X')||(mat[i-3][j+1]=='K'))&&(mat[i-4][j]==' '))//double eatnot straight on the border
																			{
																				mat[i-2][j+2]=' ';
																				mat[i-4][j]='O';
																				mat[i-3][j+1]=' ';
																			}
																	}
																}
															}
															else
															{
																cout<<"can't play this (face o x)";
																rep=0;
															}
														}
														else
														{
															cout<<"Can't move this(out the square)";
															rep=0;
														}
													}
													else
													{
														cout<<"Can't eat this (friend)";
														rep=0;
													}
												}
												else if (mat[i-1][j+1]==' ')
														{
															mat[i-1][j+1]=mat[i][j];
															mat[i][j]=' ';
														}
						}
					}
				}
			}
		}
		for(int j=0;j<8;j++) if(mat[0][j]=='O') mat[0][j]='R';
		if(!rep) cout<<"\nPlay again";
	}while(!rep);
}

