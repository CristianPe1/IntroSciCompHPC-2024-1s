import threading
import time
import random
import matplotlib.pyplot as plt
import matplotlib.dates as mdates
from datetime import datetime

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
    print(f"Thread {name} started.")
    logger.log_event('start', name)  # Registra el inicio.
    time.sleep(random.uniform(0.5, 2.0))  # Simula tiempo de procesamiento.
    logger.log_event('run', name)  # Registra que está corriendo.
    time.sleep(random.uniform(0.5, 2.0))  # Más tiempo de procesamiento.
    logger.log_event('end', name)  # Registra el final.
    
    print(f"Thread {name} finished.")

def manage_threads(threads):
    """
    Inicia y espera a que todos los threads en la lista proporcionada terminen.
    
    Args:
    threads (list of threading.Thread): Lista de threads que serán gestionados.
    """
    for thread in threads:
        thread.start()  # Inicia cada thread en la lista.
    for thread in threads:
        thread.join()  # Espera a que cada thread en la lista termine.
    print(f"Current active threads: {threading.active_count() - 1}")  # Imprime el número de threads activos.

def create_threads(num,logger):
    """
    Crea una lista de threads basada en un número dado.
    
    Args:
    num (int): Número de threads a crear.
    
    Returns:
    list of threading.Thread: Lista de threads creados.
    """
    return [threading.Thread(target=thread_function, args=(f"Thread-{i+1}", logger)) for i in range(num)]

logger = ThreadLogger()

# Fase de inicio
initial_threads = create_threads(random.randint(3, 5), logger)
print("Starting initial threads...")
manage_threads(initial_threads)

# Simula un intervalo de tiempo antes de cambiar la carga de trabajo.
time.sleep(2) 

# Fase durante la ejecución: Ajusta el número de threads activos.
adjustment = random.randint(-2, 2)
current_count = len(initial_threads) + adjustment
additional_threads = create_threads(max(1, current_count), logger)  # Asegura al menos 1 thread
manage_threads(additional_threads)

# Fase final: Ajusta el número de threads una vez más antes de finalizar el programa.
# Ajuste final
time.sleep(2)
final_adjustment = random.randint(-2, 2)
final_count = current_count + final_adjustment
final_threads = create_threads(max(1, final_count),logger)
manage_threads(final_threads)

# Visualización
logger.visualize()