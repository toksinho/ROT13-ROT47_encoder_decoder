#include <gtk/gtk.h>
#include "encode.h"

using namespace std;


void on_window_destroy (GtkWidget *widget, gpointer data)
{
  gtk_main_quit ();
}

/* Callback for rot13 button */
void rot13_clicked (GtkWidget *button, GtkTextView *txt)
{
  GtkTextIter start;
  GtkTextIter end_of;
  GtkTextBuffer *buffer;
  buffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW (txt));
  string text;


  gtk_text_buffer_get_start_iter (buffer, &start);
  gtk_text_buffer_get_end_iter (buffer, &end_of);


  text = gtk_text_buffer_get_text (buffer, &start, &end_of, FALSE);
  encode13(text);
  gtk_text_buffer_set_text(buffer,text.c_str(),-1);
  gtk_text_view_set_buffer(txt,buffer);


}
/* Callback for rot47 button */
void rot47_clicked (GtkWidget *button, GtkTextView *txt)
{
  GtkTextIter start;
  GtkTextIter end_of;
  GtkTextBuffer *buffer;
  buffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW (txt));
  string text;

  gtk_text_buffer_get_start_iter (buffer, &start);
  gtk_text_buffer_get_end_iter (buffer, &end_of);

  text = gtk_text_buffer_get_text (buffer, &start, &end_of, FALSE);
  encode47(text);
  gtk_text_buffer_set_text(buffer,text.c_str(),-1);
  gtk_text_view_set_buffer(txt,buffer);


}
int main(int argc, char *argv[])
{
  GtkWidget *window;
  GtkWidget *vbox;
  GtkWidget *hbox;
  GtkWidget *text_view;
  GtkWidget *button13;
  GtkWidget *button47;
  GtkTextBuffer *buffer;

  gtk_init (&argc, &argv);

  /* Create a Window. */
  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (window), "ROT13/ROT47 Encode/Decode");

  gtk_window_set_default_size (GTK_WINDOW (window), 400, 250);
  g_signal_connect (G_OBJECT (window), "destroy",
                    G_CALLBACK (on_window_destroy),
                    NULL);

 /* vertical box will hold textview and horizontal box*/
  vbox = gtk_vbox_new (FALSE, 2);
  gtk_container_add (GTK_CONTAINER (window), vbox);
  hbox = gtk_hbox_new(FALSE,2);

  /* multiline text widget. */
  text_view = gtk_text_view_new ();
  gtk_box_pack_start (GTK_BOX (vbox), text_view, 1, 1, 0);

  /* Obtaining the buffer associated with the widget. */
  buffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW (text_view));


  /* Create a 2 buttons. */
  button13 = gtk_button_new_with_label ("Rot 13");
  button47= gtk_button_new_with_label ("Rot 47");

  /*set button sizes, half of window width*/
  gtk_widget_set_size_request(GTK_WIDGET(button13),200,50);
  gtk_widget_set_size_request(GTK_WIDGET(button47),200,50);

  gtk_box_pack_start (GTK_BOX (hbox), button13, 0, 0, 0);
  gtk_box_pack_start (GTK_BOX (hbox), button47,0, 0, 0);
  gtk_box_pack_start (GTK_BOX (vbox), hbox, 0, 0, 0);

  g_signal_connect (G_OBJECT (button13), "clicked",
                    G_CALLBACK (rot13_clicked),
                    GTK_TEXT_VIEW (text_view));

  g_signal_connect (G_OBJECT (button47), "clicked",
                    G_CALLBACK (rot47_clicked),
                    GTK_TEXT_VIEW (text_view));
  gtk_widget_show_all (window);

  gtk_main ();

  return 0;
}



