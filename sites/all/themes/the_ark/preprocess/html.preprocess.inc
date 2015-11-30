<?php

function the_ark_preprocess_html (&$variables) {
  drupal_add_js(drupal_get_path('theme', 'the_ark') . '/libraries/jquery.browser/dist/jquery.browser.min.js',
    array(
      'group' => JS_LIBRARY,
    )
  );
  drupal_add_js(drupal_get_path('theme', 'the_ark') . '/libraries/headroom.js/dist/headroom.min.js',
    array(
      'group' => JS_LIBRARY,
    )
  );
  drupal_add_js(drupal_get_path('theme', 'the_ark') . '/libraries/headroom.js/dist/jQuery.headroom.min.js',
    array(
      'group' => JS_LIBRARY,
    )
  );
  drupal_add_js(drupal_get_path('theme', 'the_ark') . '/libraries/Tocca.js/Tocca.min.js',
    array(
      'group' => JS_LIBRARY,
    )
  );
  drupal_add_js(drupal_get_path('theme', 'the_ark') . '/js/the-ark.lte-ie9.min.js',
    array(
      'group' => JS_THEME,
      'browsers' => array(
        'IE' => 'lte IE 9',
        '!IE' => FALSE
      ),
      'preprocess' => FALSE,
    )
  );
  drupal_add_js( // Facebook JavaScript SDK
    'window.fbAsyncInit = function() {
      FB.init({
        appId      : \'1485589191708334\',
        xfbml      : true,
        version    : \'v2.1\'
      });
    };

    (function(d, s, id){
       var js, fjs = d.getElementsByTagName(s)[0];
       if (d.getElementById(id)) {return;}
       js = d.createElement(s); js.id = id;
       js.src = "//connect.facebook.net/en_US/sdk.js";
       fjs.parentNode.insertBefore(js, fjs);
     }(document, \'script\', \'facebook-jssdk\'));',
    array(
      'type' => 'inline',
    )
  );


  // Add conditional stylesheets for IE
  drupal_add_css(drupal_get_path('theme', 'the_ark') . '/css/the-ark.lte-ie9.min.css',
    array(
      'group' => CSS_THEME,
      'browsers' => array(
        'IE' => 'lte IE 9',
        '!IE' => FALSE,
      ),
      'preprocess' => FALSE,
    )
  );
  drupal_add_css(drupal_get_path('theme', 'the_ark') . '/css/the-ark.lte-ie8.min.css',
    array(
      'group' => CSS_THEME,
      'browsers' => array(
        'IE' => 'lte IE 8',
        '!IE' => FALSE,
      ),
      'preprocess' => FALSE,
    )
  );
}
