import threading
import time
import matplotlib.pyplot as plt
import matplotlib.dates as mdates
from datetime import datetime
import random

class ThreadLogger:
    """
    Esta clase se encarga de registrar los eventos de cada thread y visualizarlos en un gráfico.
    """
    def __init__(self):
        self.events = []  # Lista para almacenar los eventos de los threads.

    def log_event(self, event_type, thread_name):
        """
        Registra un evento de un thread en un momento específico.

        Args:
        event_type (str): Tipo de evento ('start', 'run', 'end').
        thread_name (str): Nombre del thread que genera el evento.
        """
        self.events.append((datetime.now(), event_type, thread_name))

    def visualize(self):
        """
        Genera un gráfico que muestra los eventos de los threads en una línea de tiempo.
        """
        fig, ax = plt.subplots(figsize=(10, 6))
        colors = {'start': 'green', 'run': 'blue', 'end': 'red'}  # Colores para cada tipo de evento.
        # Diccionario para asignar un índice único a cada thread para el eje y.
        thread_ids = {name: i for i, name in enumerate(set(event[2] for event in self.events), start=1)}
        
        # Graficar los eventos de cada thread y conectarlos con líneas.
        for event in self.events:
            x, event_type, thread_name = event
            y = thread_ids[thread_name]
            ax.scatter(x, y, color=colors[event_type], label=f"{event_type} {thread_name}" if event_type == 'start' else "")
            # Dibuja líneas desde el inicio hasta el final para cada thread.
            if event_type == 'end':
                start_time = next(e[0] for e in self.events if e[2] == thread_name and e[1] == 'start')
                ax.plot([start_time, x], [y, y], color="gray")  # Conecta el inicio y el final.

        ax.legend(title="Event Types")
        ax.set_xlabel("Time")  # Etiqueta para el eje X.
        ax.set_ylabel("Thread Number")  # Etiqueta para el eje Y.
        ax.set_title("Thread Events Visualization")  # Título del gráfico.

        # Formateo de fechas y rotación de etiquetas del eje X.
        ax.xaxis.set_major_formatter(mdates.DateFormatter('%H:%M:%S'))
        plt.xticks(rotation=45)
        plt.tight_layout()
        plt.show()

def thread_function(name, logger):
    """
    Función simulada para el trabajo de un thread, registrando varios eventos.

    Args:
    name (str): Nombre del thread.
    logger (ThreadLogger): Instancia de logger para registrar eventos.
    """
    logger.log_event('start', name)  # Registra el inicio.
    time.sleep(random.uniform(0.5, 2.0))  # Simula tiempo de procesamiento.
    logger.log_event('run', name)  # Registra que está corriendo.
    time.sleep(random.uniform(0.5, 2.0))  # Más tiempo de procesamiento.
    logger.log_event('end', name)  # Registra el final.

logger = ThreadLogger()

threads = []
n_trheads_max = 4
n_trheads_min = 1
num_threads = random.randint(n_trheads_min, n_trheads_max)
for i in range(num_threads):
    thread_name = f"Thread-{i+1}"
    thread = threading.Thread(target=thread_function, args=(thread_name, logger))
    threads.append(thread)
    thread.start()

for thread in threads:
    thread.join()

logger.visualize()
