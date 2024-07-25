import numpy as np
import matplotlib.pyplot as plt
import cv2
#import os
#os.environ['TF_ENABLE_ONEDNN_OPTS'] = '0'
import tensorflow as tf
from tensorflow.keras.preprocessing import image
#print("TF_ENABLE_ONEDNN_OPTS:", os.environ.get('TF_ENABLE_ONEDNN_OPTS'))


# incarcarea modelului antrenat
interpreter = tf.lite.Interpreter(model_path=r'C:\Users\user\PycharmProjects\AI\trained_model\cnn-rf-classifier-model-skin.tflite')
interpreter.allocate_tensors()

# selectarea tensorilor de input si output
input_details = interpreter.get_input_details()
output_details = interpreter.get_output_details()


# functia de incarcare si preprocesare a imaginii
def load_and_preprocess_image(image_path, input_shape):
    # incarcarea imaginii
    img = image.load_img(image_path, target_size=(input_shape[1], input_shape[2]))

    # transformarea imaginii intr-o matrice NumPy
    img_array = image.img_to_array(img)

    # reducerea valorilor pixelilor in intervalul [0, 1] (functioneaza mai bine fara reducere)
    # img_array = img_array.astype(np.float32) / 255.0

    # dimensiunea batch-ului ((de la (height, width, channels) la (1, height, width, channels))
    img_array = np.expand_dims(img_array, axis=0)
    # print(img_array)
    return img_array


# path-ul imaginii
image_path = r'C:\Users\user\PycharmProjects\AI\photos\img5_crop.jpg'
# image_path = r'C:\Users\user\PycharmProjects\AI\photos\img7.jpg'

# dimensiunea input-ului ceruta de model
input_shape = input_details[0]['shape']

# preprocesarea imaginii
input_data = load_and_preprocess_image(image_path, input_shape)

# setarea tensorului pentru rulare
interpreter.set_tensor(input_details[0]['index'], input_data)

# inference run
interpreter.invoke()

# datele de output
output_data = interpreter.get_tensor(output_details[0]['index'])
print(output_data)

# procesarea datelor in diagnostic
predicted_class = np.argmax(output_data)
percentage = np.max(output_data)
percentage *=100
predicted_percentage = format(percentage, ".3f")
print(f"Predicted class: {predicted_class}")
print('Predicted percentage:', predicted_percentage)

if(predicted_class == 4):
    text = 'Alunita este necanceroasa '
    print('Alunita este necanceroasa ' + str(predicted_percentage) + '%')
else:
    text = 'Alunita este canceroasa '
    print('Alunita este canceroasa ' + str(predicted_percentage) + '%')

# classes = {4: ('nv', ' melanocytic nevi'),
           # 6: ('mel', 'melanoma'),
           # 2: ('bkl', 'benign keratosis-like lesions'),
           # 1: ('bcc' , ' basal cell carcinoma'),
           # 5: ('vasc', ' pyogenic granulomas and hemorrhage'),
           # 0: ('akiec', 'Actinic keratoses and intraepithelial carcinomae'),
           # 3: ('df', 'dermatofibroma')}

image = cv2.imread(image_path)
image_rgb = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)
# image = np.squeeze(input_data)
# image = np.squeeze(image)
predicted_class = np.argmax(output_data)
class_labels = {4: ('nv', ' melanocytic nevi'),
           6: ('mel', 'melanoma'),
           2: ('bkl', 'benign keratosis-like lesions'),
           1: ('bcc', ' basal cell carcinoma'),
           5: ('vasc', ' pyogenic granulomas and hemorrhage'),
           0: ('akiec', 'Actinic keratoses and intraepithelial carcinomae'),
           3: ('df', 'dermatofibroma')}
predicted_label = class_labels[predicted_class]

print(predicted_label)

plt.figure(figsize=(10, 4))
plt.subplot(1, 2, 1)
plt.title('Loaded image', fontsize=18)
plt.imshow(image_rgb)
plt.axis('off')

plt.subplot(1, 2, 2)
plt.title('Predicted data', fontsize=18)
plt.text(0.0, 0.75, 'Predicted class: ' + str(predicted_class), fontsize=15, va='center')
plt.text(0.0, 0.55, 'Predicted percentage: ' + str(predicted_percentage) + '%', fontsize=15, va='center')
plt.text(0.0, 0.35, 'Class name: ' + str(predicted_label), fontsize=15, va='center')
plt.text(0.0, 0.15, text, fontsize=15, va='center')
plt.axis('off')
plt.show()









