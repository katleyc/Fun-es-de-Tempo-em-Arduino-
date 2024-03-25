using System;
using System.Threading;
using Microsoft.Maker.RemoteWiring;

namespace ArduinoLEDControl
{
    class Program
    {
        static int Main(string[] args)
        {
            // Conecte-se ao Arduino via porta serial
            RemoteDevice session = new RemoteDevice("COM3"); // Altere para a porta serial correta do seu Arduino

            // Loop principal
            while (true)
            {
                // Pisca o LED a cada 350ms
                session.pinMode(13, PinMode.OUTPUT);
                session.digitalWrite(13, PinState.HIGH);
                Thread.Sleep(350);
                session.digitalWrite(13, PinState.LOW);
                Thread.Sleep(350);

                // Verifica se o botão foi pressionado
                PinState buttonState = session.digitalRead(2);
                if (buttonState == PinState.LOW)
                {
                    // Liga o LED
                    session.digitalWrite(13, PinState.HIGH);
                    Thread.Sleep(5000); // Mantém ligado por 5 segundos
                    session.digitalWrite(13, PinState.LOW); // Desliga o LED
                }
            }

            return 0;
        }
    }
}
