<?php

function the_ark_preprocess_image (&$variables) {
  $variables['attributes']['class'][] = 'content-image';
}
