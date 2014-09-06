(function ($) {
  Drupal.admin.behaviors.theArkAdminFormSpotify = function () {
    var spotifyContainer = $('.field-name-field-spotify-uri');
    if (spotifyContainer.length === 0) return;

    var appendSpotify = function () {
      spotifyContainer.append(spotifyPreview);
      spotifyAppended = true;
    }, removeSpotify = function () {
      spotifyPreview.remove();
      spotifyAppended = false;
    };

    var spotifyAppended = false
      , spotifyBase = 'https://embed.spotify.com/?uri='
      , spotifyField = $('.field-name-field-spotify-uri .form-text')
      , spotifyPreview = $(document.createElement('iframe'));

    spotifyPreview.attr({
      allowtransparency: true,
      frameborder: 0,
      height: 380,
      src: spotifyBase + spotifyField.val(),
      width: 300
    });
    if (spotifyField.val()) appendSpotify();
    
    spotifyField.blur(function () {
      spotifyPreview.attr({
        src: spotifyBase + spotifyField.val()
      });
      if (spotifyAppended === false && spotifyField.val()) appendSpotify();
      else if (spotifyAppended === true && !spotifyField.val()) removeSpotify();
    });
  };
})(jQuery);
