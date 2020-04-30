#include "header_1301191171.h"

void createNode(string X, adrNode &P) {
    P = new node;
    info(P) = X;
    next(P) = NULL;
    edge(P) = NULL;
    counts(P) = 0;
}
void createGraph(Graph &G) {
    row(G) = NULL;
    column(G) = NULL;
}
void insertLast(adrNode &first, adrNode P) {
    if(first == NULL) {
        first = P;
    } else {
        adrNode Q = first;
        while(next(Q)!=NULL) {
            Q = next(Q);
        }
        next(Q) = P;
    }
}
void addNode(Graph &G, string X, string Y) {
    adrNode P;
    adrNode Q;
    createNode(Y, Q);
    createNode(X, P);
    //cout<<"cek1";
    if(row(G)!=NULL&&column(G)!=NULL) {
        //cout<<"cek2";
        adrNode ada = findNode(row(G), X);
        adrNode ada2 = findNode(column(G), Y);
        if(ada == NULL&&ada2==NULL) {
            //cout<<"cek3";
            if(X!=".") {
                insertLast(row(G), P);
            }
            if(Y!=".") {
                insertLast(column(G), Q);
            }
        } else if(ada!=NULL&&ada2==NULL) {
            if(Y!=".") {
                insertLast(column(G), Q);
            }
        } else if(ada==NULL&&ada2!=NULL) {
            if(X!=".") {
                insertLast(row(G), P);
            }
        }
    } else {
        //cout<<"else";
        insertLast(row(G), P);
        insertLast(column(G), Q);
    }
}
adrNode findNode(adrNode first, string X) {
    adrNode P = first;
    //transform(X.begin(), X.end(), X.begin(), ::tolower);
    if(first!=NULL) {
        while(info(P)!=X&&next(P)!=NULL) {
            P = next(P);
        }
    }
    if(info(P)==X) {
        return P;
    } else {
        return NULL;
    }
}
adrEdge findEdge(adrEdge first, string X) {
    adrEdge P = first;
    //transform(X.begin(), X.end(), X.begin(), ::tolower);
    if(first!=NULL) {
        while((info(infor(P))!=X)&&(nextr(P)!=NULL)) {
            P = nextr(P);
        }
    }
    if(info(infor(P))==X) {
        return P;
    } else {
        return NULL;
    }
}
adrEdge alokasi(adrNode Q) {
    adrEdge R = new Edge;
    infor(R) = Q;
    nextr(R) = NULL;
    return R;
}
void connect(Graph &G, string X, string Y) {
    if(row(G)!=NULL&&column(G)!=NULL) {
        adrNode P = findNode(row(G), X);
        adrNode Q = findNode(column(G), Y);
        adrEdge R = alokasi(Q);
        nextr(R) = edge(P);
        edge(P) = R;
        counts(P)++;
    } else {
    cout<<"\nList Kosong!"<<endl;
  }
}
void printGraph(Graph G) {
    adrNode P = row(G);
    adrEdge Q;
    adrNode R;
    if(P!=NULL) {
        while(next(P)!=NULL) {
            cout<<"Judul Film :"<<info(P);
            Q = edge(P);
            if(edge(P)!=NULL) {
                cout<<"\nPemeran : ";
                while(nextr(Q)!=NULL) {
                    R = infor(Q);
                    cout<<info(R);
                    cout<<", ";
                    Q = nextr(Q);
                }
                if(nextr(Q)==NULL) {
                    R = infor(Q);
                    cout<<info(R);
                    cout<<", ";
                }
            }
            P = next(P);
            cout<<endl;
        }
        if(next(P)==NULL) {
            cout<<"Judul Film :"<<info(P);
            Q = edge(P);
            if(edge(P)!=NULL) {
                cout<<"\nPemeran : ";
                while(nextr(Q)!=NULL) {
                    R = infor(Q);
                    cout<<info(R);
                    cout<<", ";
                    Q = nextr(Q);
                }
                if(nextr(Q)==NULL) {
                    R = infor(Q);
                    cout<<info(R);
                    cout<<", ";
                }
            }
            cout<<endl;
        }
    } else {
    cout<<"\nList Kosong!"<<endl;
  }
}
void seringMain(Graph G) {
    adrEdge Q;
    adrNode P, S;
    adrNode temp;
    P = row(G);
    if(P!=NULL) {
        if(next(P)!=NULL) {
            while(next(P)!=NULL) {
                Q = edge(P);
                if(Q!=NULL) {
                    if(nextr(Q)!=NULL) {
                        while(nextr(Q)!=NULL) {
                            counts(infor(Q))++;
                            Q=nextr(Q);
                        }
                        counts(infor(Q))++;
                    } else {
                        counts(infor(Q))++;
                    }
                }
            P = next(P);
            }
            Q = edge(P);
            while(nextr(Q)!=NULL) {
                counts(infor(Q))++;
                Q=nextr(Q);
            }
            counts(infor(Q))++;
        } else {
                Q = edge(P);
                if(Q!=NULL) {
                    if(nextr(Q)!=NULL) {
                        while(nextr(Q)!=NULL) {
                            counts(infor(Q))++;
                            Q=nextr(Q);
                        }
                        counts(infor(Q))++;
                    } else {
                        counts(infor(Q))++;
                    }
                }
        }
        S = column(G);
        if(S!=NULL) {
        temp = S;
            while(next(S)!=NULL) {
                if(counts(next(S)) > counts(temp)) {
                    temp = next(S);
                }
                S = next(S);
            }
            if(counts(S)>counts(temp)) {
                temp = S;
            }
        } else {
            temp = S;
        }
        cout<<"Aktor/Aktris: "<<info(temp)<<" dengan "<<counts(temp)<<" film yang dimainkan"<<endl;
    } else {
    cout<<"\nList Kosong!"<<endl;
  }
}
void filmSama(Graph G) {
    Graph G1;
    createGraph(G1);
    adrNode F1, F2;
    adrEdge P, Q;
    adrEdge cek;
    F1 = row(G);
    if(F1!=NULL) {
        if(next(F1)!=NULL) {
            while(next(F1)!=NULL) {
                F2 = next(F1);
                while(next(F2)!=NULL) {
                    P = edge(F1);
                    Q = edge(F2);
                    cek = findEdge(edge(F2), info(infor(P)));
                    while(nextr(P)!=NULL) {
                        cek = findEdge(edge(F2), info(infor(P)));
                        if(cek != NULL) {
                            adrNode R;
                            createNode(info(F1)+" dan "+info(F2), R);
                            addNode(G1, info(F1)+" dan "+info(F2), info(infor(cek)));
                            connect(G1, info(F1)+" dan "+info(F2), info(infor(cek)));
                            counts(R)++;
                        }
                        P = nextr(P);
                    }
                    if(nextr(P)==NULL) {
                        cek = findEdge(edge(F2), info(infor(P)));
                        if(cek != NULL) {
                            adrNode R;
                            createNode(info(F1)+" dan "+info(F2), R);
                            addNode(G1, info(F1)+" dan "+info(F2), info(infor(cek)));
                            connect(G1, info(F1)+" dan "+info(F2), info(infor(cek)));
                            counts(R)++;
                        }
                    }
                    F2 = next(F2);
                }
                if(next(F2)==NULL){
                    P = edge(F1);
                    Q = edge(F2);
                    while(nextr(P)!=NULL) {
                        cek = findEdge(edge(F2), info(infor(P)));
                        if(cek != NULL) {
                            adrNode R;
                            createNode(info(F1)+" dan "+info(F2), R);
                            addNode(G1, info(F1)+" dan "+info(F2), info(infor(cek)));
                            connect(G1, info(F1)+" dan "+info(F2), info(infor(cek)));
                            counts(R)++;
                        }
                        P = nextr(P);
                    }
                    if(nextr(P)==NULL) {
                        cek = findEdge(edge(F2), info(infor(P)));
                        if(cek != NULL) {
                            adrNode R;
                            createNode(info(F1)+" dan "+info(F2), R);
                            addNode(G1, info(F1)+" dan "+info(F2), info(infor(cek)));
                            connect(G1, info(F1)+" dan "+info(F2), info(infor(cek)));
                            counts(R)++;
                        }
                    }
                }
                F1 = next(F1);
            }

            printGraphKW(G1,2);
        }
    } else {
    cout<<"\nList Kosong!"<<endl;
  }
}
void printGraphKW(Graph G, int syarat) {
    adrNode P = row(G);
    adrEdge Q;
    adrNode R;
    if(P!=NULL) {
        while(next(P)!=NULL) {
        if(counts(P)==syarat) {
            cout<<"Judul Film :"<<info(P);
            Q = edge(P);
            if(edge(P)!=NULL) {
                cout<<"\nPemeran : ";
                while(nextr(Q)!=NULL) {
                    R = infor(Q);
                    cout<<info(R);
                    cout<<", ";
                    Q = nextr(Q);
                }
                if(nextr(Q)==NULL) {
                    R = infor(Q);
                    cout<<info(R);
                    cout<<", ";
                }
            }
            cout<<endl;
            }
            P = next(P);
        }
        if(next(P)==NULL&&counts(P)==syarat) {
            cout<<"Judul Film :"<<info(P);
            Q = edge(P);
            if(edge(P)!=NULL) {
                cout<<"\nPemeran : ";
                while(nextr(Q)!=NULL) {
                    R = infor(Q);
                    cout<<info(R);
                    cout<<", ";
                    Q = nextr(Q);
                }
                if(nextr(Q)==NULL) {
                    R = infor(Q);
                    cout<<info(R);
                    cout<<", ";
                }
            }
            cout<<endl;
        }
    } else {
    cout<<"\nList Kosong!"<<endl;
  }
}
void deleteFilm(Graph &G, string X) {
  adrNode P = findNode(row(G), X);
  adrNode Q;
  if(P!=NULL) {
    if(row(G)==P) {
        row(G) = next(P);
        next(P) = NULL;
    } else {
        Q = row(G);
      	while(next(Q)!=P) {
        	Q = next(Q);
      	}
        if(next(P)==NULL) {
            next(Q) = NULL;
        } else {
            next(Q) = next(P);
            next(P) = NULL;
        }
    }
    } else {
    cout<<"\nList Kosong!"<<endl;
  }
}
void deleteAktorCol(Graph &G, string X) {
  adrNode P = findNode(column(G), X);
  adrNode Q;
  if(P!=NULL) {
    if(column(G)==P) {
        column(G) = next(P);
        next(P) = NULL;
    } else {
        Q = column(G);
      	while(next(Q)!=P) {
        	Q = next(Q);
      	}
        if(next(P)==NULL) {
            next(Q) = NULL;
        } else {
            next(Q) = next(P);
            next(P) = NULL;
        }
    }
    } else {
    cout<<"\nList Kosong!"<<endl;
  }
}
void deleteAktor(Graph &G, string X) {
  adrNode P = column(G);
  adrEdge R;
  adrNode S = row(G);
  if(S!=NULL&&P!=NULL) {
    while(next(S)!=NULL) {
      R = findEdge(edge(S), X);
      if(R!=NULL) {
        if(edge(S)==R) {
            edge(S) = nextr(R);
            nextr(R) = NULL;
            counts(S)--;
        } else {
            adrEdge Q = edge(S);
            while(nextr(Q)!=R) {
                Q = nextr(Q);
            }
            if(nextr(R)==NULL) {
                nextr(Q) = NULL;
                counts(S)--;
            } else {
                nextr(Q) = nextr(R);
                nextr(R) = NULL;
                counts(S)--;
            }
        }
      }
      S = next(S);
    }
    if(next(S)==NULL) {
      R = findEdge(edge(S), X);
      if(R!=NULL) {
        if(edge(S)==R) {
            edge(S) = nextr(R);
            nextr(R) = NULL;
            counts(S)--;
        } else {
            adrEdge Q = edge(S);
            while(nextr(Q)!=R) {
                Q = nextr(Q);
            }
            if(nextr(R)==NULL) {
                nextr(Q) = NULL;
                counts(S)--;
            } else {
                nextr(Q) = nextr(R);
                nextr(R) = NULL;
                counts(S)--;
            }
        }
      }
    }
    deleteAktorCol(G, X);
  } else {
    cout<<"\nList Kosong!"<<endl;
  }
}
void filmYangArtisnyaBanyak(Graph G) {
  adrNode P = row(G);
  int temp = 0;
  if(P!=NULL) {
    while(next(P)!=NULL) {
        if(counts(P)>temp) {
            temp = counts(P);
        }
        P = next(P);
	}
    if(next(P)==NULL) {
      if(counts(P)>temp) {
            temp = counts(P);
        }
    }
    printGraphKW(G, temp);
  } else {
    cout<<"\nList Kosong!"<<endl;
  }
}
void showParticularMovie(Graph G, string X) {
  vector<string> listFilm;
  adrNode P = row(G);
  adrEdge Q;
  if(P!=NULL) {
    while(next(P)!=NULL) {
      Q = findEdge(edge(P), X);
        if(Q!=NULL) {
          if(info(infor(Q))==X) {
			listFilm.push_back(info(P));
          }
        }
      P = next(P);
    }
    if(next(P)==NULL) {
      Q = findEdge(edge(P), X);
        if(Q!=NULL) {
          if(info(infor(Q))==X) {
			listFilm.push_back(info(P));
          }
        }
    }
    if(listFilm.empty()==false) {
      cout<<"Daftar Film yang dibintangi oleh "<<X<<" adalah"<<endl;
      for(int i=0; i<listFilm.size(); i++) {
        cout<<i+1<<". "<<listFilm[i]<<endl;
      }
    } else {
        cout<<"\nMohon maaf nama aktor/aktris tidak ditemukan!"<<endl;
    }
  }
}

void menuUtama(Graph &G) {
    cout<<"---------------------------------------------------------------------------"<<endl;
    cout<<"1. Menambahkan aktor/aktris baru"<<endl;
    cout<<"2. Menambahkan film baru"<<endl;
    cout<<"3. Menambahkan hubungan antara aktor/aktris dan film"<<endl;
    cout<<"4. Menghapus aktor/aktris tertentu"<<endl;
    cout<<"5. Menghapus film tertentu"<<endl;
    cout<<"6. Menampilkan semua film yang pernah diperankan oleh aktirs/aktor tertentu"<<endl;
    cout<<"7. Menampilkan dua aktor/aktris yang pernah dua kali terlibat dalam film yang sama"<<endl;
    cout<<"8. Menampilkan film yang paling banyak melibatkan aktor/aktris"<<endl;
    cout<<"9. Menampilkan aktor/aktris yang paling sering bermain film"<<endl;
    cout<<"10. Menampilkan semua film dan pemerannya"<<endl;
    cout<<"11. Keluar"<<endl;
    cout<<"---------------------------------------------------------------------------"<<endl;
    cout<<"Masukkan pilihan menu: ";
    int menu = -1;
    cin>>menu;
    if(menu>0&&menu<12) {
        pilihan(G, menu);
    } else {
        cout<<"Pastikan untuk menggunakan angka yang sesuai dengan menu yang ada!";
        menuUtama(G);
    }

}
void pilihan(Graph &G, int menu) {
string masukan, masukan2;
    switch (menu) {
        case 1:
            cin.ignore();
            cout<<"Masukkan nama aktor/aktris (Case Sensitive): ";
            getline(cin,masukan);
            addNode(G, ".", masukan);
            break;
        case 2:
            cin.ignore();
            cout<<"Masukkan judul film (Case Sensitive): ";
            getline(cin,masukan);
            addNode(G, masukan, ".");
            break;
        case 3:
            cin.ignore();
            cout<<"Masukkan judul film (Case Sensitive): ";
            getline(cin,masukan);
            cout<<"Masukkan nama aktor/aktris (Case Sensitive): ";
            getline(cin,masukan2);
            connect(G, masukan, masukan2);
            break;
        case 4:
            cin.ignore();
            cout<<"Masukkan nama aktor/aktris (Case Sensitive): ";
            getline(cin,masukan);
            deleteAktor(G, masukan);
            break;
        case 5:
            cin.ignore();
            cout<<"Masukkan judul film (Case Sensitive): ";
            getline(cin,masukan);
            deleteFilm(G, masukan);
            break;
        case 6:
            cin.ignore();
            cout<<"Masukkan nama aktor/aktris (Case Sensitive): ";
            getline(cin,masukan);
            showParticularMovie(G, masukan);
            break;
        case 7:
            cout<<"Daftar aktor/aktris yang pernah dua kali terlibat dalam film yang sama:"<<endl;
            filmSama(G);
            break;
        case 8:
            cout<<"Daftar film yang paling banyak melibatkan aktor/aktris:"<<endl;
            filmYangArtisnyaBanyak(G);
            break;
        case 9:
            cout<<"Daftar aktor/aktris yang paling sering bermain film:"<<endl;
            seringMain(G);
            break;
        case 10:
            printGraph(G);
            break;
        case 11:
            keluar();
            break;
    }
    cout<<"\n---------------------------------------------------------------------------"<<endl;
    if(menu!=11)
        menuUtama(G);
}
void keluar(){
    cout<<"\nTerima Kasih!";
}
