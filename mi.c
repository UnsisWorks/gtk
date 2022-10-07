#include <gtk/gtk.h>

static void activate (GtkApplication* app,
          gpointer        user_data)
{
  GtkWidget *window; 
  GtkWidget *label, *label2, *button;

  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "Window");
  gtk_window_set_resizable(GTK_WINDOW(window), FALSE);
  gtk_window_set_default_size (GTK_WINDOW (window), 600, 200);

  button = gtk_button_new_with_label("egggr");

  label = gtk_label_new("hola");
  gtk_container_add(GTK_CONTAINER(window), button);
  label2 = gtk_label_new("hola");
  //gtk_container_add(GTK_CONTAINER(window), label2);
  gtk_widget_show_all (window);
}

int main (int  argc, char **argv) {
  GtkApplication *app;
  int status;

  app = gtk_application_new ("org.gtk.ejemplo", G_APPLICATION_FLAGS_NONE);
  g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
  status = g_application_run (G_APPLICATION (app), argc, argv);
  g_object_unref (app);

  return status;
}